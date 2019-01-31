/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lox.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:01:56 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/31 12:53:46 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_lox(t_mlx *env, int part)
{
	env->i = 0;
	if (part == 1)
	{
		env->x1 = -2.2;
		env->x2 = 1.0;
		env->y1 = -1.5;
		env->y2 = 1.0;
		env->zoom_x = 200;
		env->zoom_y = 200;
		env->c_r = env->x / env->zoom_x + env->x1;
		env->c_i = env->y / env->zoom_y + env->y1;
		env->z_r = 0;
		env->z_i = 0;
		env->iter_max = 50;
		env->img_x = WDW_WIDTH;
		env->img_y = WDW_HEIGHT;
		env->color = 0x660000;
	}
	else if (part == 2)
	{
		env->c_r = env->x / env->zoom_x + env->x1;
		env->c_i = env->y / env->zoom_y + env->y1;
		env->z_r = 0;
		env->z_i = 0;
	}
}

void	exe_lox(t_mlx *env)
{
	env->x = -1;
	while (++env->x < env->img_x)
	{
		env->y = 0;
		while (env->y < env->img_y)
		{
			init_lox(env, 2);
			while (env->z_r * env->z_r + env->z_i * env->z_i < 4
					&& env->i < env->iter_max)
			{
				env->tmp = env->z_r * env->z_r * env->z_r * env->z_r -
					env->z_i * env->z_i + env->c_r;
				env->z_i = 3 * env->z_i * env->z_r + env->c_i;
				env->z_r = env->tmp;
				env->i++;
			}
			env->i == env->iter_max ? draw(env->x, env->y, env->color, env) :
				draw(env->x, env->y, env->i * env->color / env->iter_max, env);
			env->y++;
		}
	}
}
