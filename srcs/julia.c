/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:58:10 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/31 13:27:48 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_mlx *env, int part)
{
	if (part == 1)
	{
		env->x1 = -2.2;
		env->x2 = 1.8;
		env->y1 = -2;
		env->y2 = 1.9;
		env->iter_max = 30;
		env->img_x = WDW_WIDTH;
		env->img_y = WDW_HEIGHT;
		env->zoom_x = env->img_x / (env->x2 - env->x1);
		env->zoom_y = env->img_y / (env->y2 - env->y1);
		env->color = 0xffff66;
		env->c_r = 0.285;
		env->c_i = 0.0122;
		env->z_r = 0;
		env->z_i = 0;
		env->i = 0;
	}
	else if (part == 2)
	{
		env->z_r = env->x / env->zoom_x + env->x1;
		env->z_i = env->y / env->zoom_y + env->y1;
		env->i = 0;
	}
}

void	exe_julia(t_mlx *env)
{
	env->x = 0;
	while (env->x < env->img_x)
	{
		env->y = 0;
		while (env->y < env->img_y)
		{
			init_julia(env, 2);
			while (env->z_r * env->z_r + env->z_i * env->z_i < 4
					&& env->i < env->iter_max)
			{
				env->tmp = env->z_r;
				env->z_r = env->z_r * env->z_r - env->z_i * env->z_i + env->c_r;
				env->z_i = 2 * env->z_i * env->tmp + env->c_i;
				env->i++;
			}
			env->i == env->iter_max ? draw(env->x, env->y, env->color, env) :
				draw(env->x, env->y, env->i * env->color / env->iter_max, env);
			env->y++;
		}
		env->x++;
	}
}
