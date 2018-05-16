/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:58:19 by arive-de          #+#    #+#             */
/*   Updated: 2018/04/25 16:56:33 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_mlx *env)
{
	env->mlx_ptr = mlx_init();
	env->wdw = mlx_new_window(env->mlx_ptr, WDW_WIDTH, WDW_HEIGHT, "Fractol");
	env->img->img_ptr = mlx_new_image(env->mlx_ptr, WDW_WIDTH, WDW_HEIGHT);
	env->img->data = mlx_get_data_addr(env->img->img_ptr, &env->img->bpp,
			&env->img->size_l, &env->img->endian);
}

int		key_funct(int key, t_mlx *env)
{
	//printf("keycode = %d\n", key);
	env->x = 0; //TO DO ERASE
	if (key == 53)
	{
		//	TO DO FREE
		exit(0);
	}
	if (key == 15)
	{
		env->color = 0x00FF0000;
	}
	if (key == 69)
	{
	}
	if (key == 78)
	{
	}
	if (key == 123)
	{
		env->x1 += 0.1;
	}
	if (key == 124)
	{
		env->x1 -= 0.1;
	}
	if (key == 126)
	{
		env->y1 += 0.1;
	}
	if (key == 125)
	{
		env->y1 -= 0.1;
	}
	exec_mandelbrot(env);

	return (0);
}

int		mouse_funct(int key, int x, int y, t_mlx *env)
{
	double h;

	h = 0;
	init_mandelbrot(env, 1);
	printf("key = %d\n", key);
	if (key == 1)
	{
		//printf("x = %f\ny = %f\n", x, y);
		env->x1 = x * 0.01 - h;
		env->x2 = x * 0.01 + h;
		env->y1 = y * 0.01 - h;
		env->y2 = y * 0.01 + h;
		env->zoom_x *= 2;
		env->zoom_y *= 2;
		env->iter_max *= 2;
	}
	exec_mandelbrot(env);
	return (0);
}

void	img_to_wdw(t_mlx *env)
{
	mlx_clear_window(env->img, env->wdw);
	mlx_put_image_to_window(env->mlx_ptr, env->wdw, env->img->img_ptr, 0, 0);
	mlx_key_hook(env->wdw, key_funct, env);
	mlx_mouse_hook(env->wdw, mouse_funct, env);
	//mlx_loop_hook(env->mlx_ptr, mouse_funct, 0);
	mlx_loop(env->mlx_ptr);
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
