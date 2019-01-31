/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:58:19 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/31 13:42:36 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init(t_mlx *env)
{
	env->mlx_ptr = mlx_init();
	env->wdw = mlx_new_window(env->mlx_ptr, WDW_WIDTH, WDW_HEIGHT, "Fractol");
	img_to_wdw(env);
}

int		key_funct(int key, t_mlx *env)
{
	if (key == 53)
	{
		free(env->img);
		free(env);
		exit(1);
	}
	if (key == 15)
		env->color = env->color + 0xf00000;
	if (key == 123)
		env->x1 -= 0.1;
	if (key == 124)
		env->x1 += 0.1;
	if (key == 126)
		env->y1 -= 0.1;
	if (key == 125)
		env->y1 += 0.1;
	img_to_wdw(env);
	return (0);
}

int		zoom_funct(int key, int x, int y, t_mlx *env)
{
	double tmp_x;
	double tmp_y;

	tmp_x = x / env->zoom_x + env->x1;
	tmp_y = y / env->zoom_y + env->y1;
	if (key == 4)
	{
		env->zoom_x /= 1.1;
		env->zoom_y /= 1.1;
	}
	if (key == 5)
	{
		env->zoom_x *= 1.1;
		env->zoom_y *= 1.1;
	}
	env->x1 = tmp_x - (x / env->zoom_x);
	env->y1 = tmp_y - (y / env->zoom_y);
	img_to_wdw(env);
	return (0);
}

int		julia_funct(int x, int y, t_mlx *env)
{
	if (x < WDW_WIDTH && x > 0 && y < WDW_HEIGHT && y > 0)
	{
		env->c_r = (double)(x + 400 - WDW_WIDTH) / 500;
		env->c_i = (double)(y + 400 - WDW_HEIGHT) / 500;
	}
	img_to_wdw(env);
	return (0);
}

void	draw(int x, int y, int color, t_mlx *env)
{
	int index;
	int *ptr;

	if (x >= 0 && x < WDW_WIDTH && y >= 0 && y < WDW_HEIGHT)
	{
		index = y * env->img->size_l + x * env->img->bpp / 8;
		ptr = (int*)&env->img->data[index];
		*ptr = color;
	}
}
