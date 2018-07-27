/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:22:00 by arive-de          #+#    #+#             */
/*   Updated: 2018/04/17 11:46:42 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		which_fract(t_mlx *env, char *str)
{
	if (ft_strcmp("julia", str) == 0)
	{
		init(env);
		init_julia(env, 1);
		exec_julia(env);
	}
	else if (ft_strcmp("mandelbrot", str) == 0)
	{
		init(env);
		init_mandelbrot(env, 1);
		exec_mandelbrot(env);
	}
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	*env;

	if (!(env = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
		return (0);
	if (!(env->img = (t_img*)ft_memalloc(sizeof(t_img))))
		return (0);
	if (argc != 2 || which_fract(env, argv[1]) != 1)
	{
		printf("TODO : print usage\n");
	}
	return (0);
}


