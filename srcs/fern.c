/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger_sponge.c                                       :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:58:15 by arive-de          #+#    #+#             */
/*   Updated: 2018/04/25 16:56:36 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fern(t_mlx *env)
{
	env->x1 = 500;
	env->y1 = 750;
	env->iter_max = 1000000;
	env->color = 0x009900;
	env->zoom = 60;
}

void	exe_fern(t_mlx *env)
{
	int i = 1;
	int d;
	double tmp = 0;

	while (i <= env->iter_max)
	{
		d = rand() % 100;
		if (d > 14)
		{
			tmp = (0.85 * env->x) + (0.04 * env->y);
			env->y = (-0.04 * env->x) + (0.85 * env->y) + 1.6;
			env->x = tmp;
		}
		else if (d > 8)
		{
			tmp = (0.2 * env->x) - (0.26 * env->y);
			env->y = (0.23 * env->x) + (0.22 * env->y) + 1.6;
			env->x = tmp;
		}
		else if (d > 1)
		{
			tmp = (-0.15 * env->x) + (0.28 * env->y);
			env->y = (0.26 * env->x) + (0.24 * env->y) + 0.44;
			env->x = tmp;
		}
		else if (d == 0)
		{
			env->x = 0;
			env->y = env->y * 0.16;
		}
		draw(env->x * env->zoom + env->x1, env->y * -env->zoom + env->y1, env->color, env);
		i++;
	}
}
