/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:58:10 by arive-de          #+#    #+#             */
/*   Updated: 2018/04/16 15:41:28 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_mlx *env, int part)
{
	if (part == 1)
	{
		env->x1 = -1.5;
		env->x2 = 1;
		env->y1 = -1.2;
		env->y2 = 1.2;
		env->zoom = 250;
		env->iter_max = 100;
		env->img_x = WDW_WIDTH;
		env->img_y = WDW_HEIGHT;
		env->x = 0;
		env->color = 0xFFFFFF;
	}
	else
	{
		env->c_r = 0.285;
		env->c_i = 0.01;
		env->z_r = env->x / env->zoom + env->x1;
		env->z_i = env->y / env->zoom + env->y1;
		env->i = 0;
	}
}

void	exec_julia(t_mlx *env)
{
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
				draw(env->x, env->y, 0, env);
			env->y++;
		}
		env->x++;
	}
	img_to_wdw(env);
}
