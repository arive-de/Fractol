/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octopus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:33:57 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/31 13:34:02 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_octopus(t_mlx *env, int part)
{
	if (part == 1)
	{
		env->x1 = -2.1;
		env->x2 = 2;
		env->y1 = -1.8;
		env->y2 = 2.2;
		env->iter_max = 60;
		env->img_x = WDW_WIDTH;
		env->img_y = WDW_HEIGHT;
		env->zoom_x = env->img_x / (env->x2 - env->x1);
		env->zoom_y = env->img_y / (env->y2 - env->y1);
		env->color = 0x660066;
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

void	exe_octopus(t_mlx *env)
{
	env->x = 0;
	while (env->x < env->img_x)
	{
		env->y = 0;
		while (env->y < env->img_y)
		{
			init_octopus(env, 2);
			while (env->z_r * env->z_r + env->z_i * env->z_i < 4
					&& env->i < env->iter_max)
			{
				env->tmp = env->z_r;
				env->z_r = env->z_r - env->z_i * env->z_i + env->c_r;
				env->z_i = 2 * -env->z_i * env->tmp + env->c_i;
				env->i++;
			}
			env->i == env->iter_max ? draw(env->x, env->y, env->color, env) :
				draw(env->x, env->y, env->i * env->color / env->iter_max, env);
			env->y++;
		}
		env->x++;
	}
}
