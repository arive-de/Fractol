/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:22:00 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/31 13:41:09 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	launch_fractal(t_mlx *env)
{
	if (env->fractal == 1)
		exe_mandelbrot(env);
	else if (env->fractal == 2)
		exe_julia(env);
	else if (env->fractal == 3)
		exe_douady(env);
	else if (env->fractal == 4)
		exe_siegel(env);
	else if (env->fractal == 5)
		exe_lox(env);
	else if (env->fractal == 6)
		exe_burningship(env);
	else if (env->fractal == 7)
		exe_tricorne(env);
	else if (env->fractal == 8)
		exe_octopus(env);
}

void	img_to_wdw(t_mlx *env)
{
	env->img->img_ptr = mlx_new_image(env->mlx_ptr, WDW_WIDTH, WDW_HEIGHT);
	env->img->data = mlx_get_data_addr(env->img->img_ptr, &env->img->bpp,
			&env->img->size_l, &env->img->endian);
	launch_fractal(env);
	mlx_clear_window(env->mlx_ptr, env->wdw);
	mlx_put_image_to_window(env->mlx_ptr, env->wdw, env->img->img_ptr, 0, 0);
	mlx_destroy_image(env->mlx_ptr, env->img->img_ptr);
}

int		init_fractal2(t_mlx *env, char *str)
{
	if (ft_strcmp("lox", str) == 0 || env->fractal == 5)
	{
		init_lox(env, 1);
		env->fractal = 5;
	}
	else if (ft_strcmp("burningship", str) == 0 || env->fractal == 6)
	{
		init_burningship(env, 1);
		env->fractal = 6;
	}
	else if (ft_strcmp("tricorne", str) == 0 || env->fractal == 7)
	{
		init_tricorne(env, 1);
		env->fractal = 7;
	}
	else if (ft_strcmp("octopus", str) == 0 || env->fractal == 8)
	{
		init_octopus(env, 1);
		env->fractal = 8;
	}
	else
	{
		return (0);
	}
	return (1);
}

int		init_fractal(t_mlx *env, char *str)
{
	if (ft_strcmp("mandelbrot", str) == 0 || env->fractal == 1)
	{
		init_mandelbrot(env, 1);
		env->fractal = 1;
	}
	else if (ft_strcmp("julia", str) == 0 || env->fractal == 2)
	{
		init_julia(env, 1);
		env->fractal = 2;
	}
	else if (ft_strcmp("douady", str) == 0 || env->fractal == 3)
	{
		init_douady(env, 1);
		env->fractal = 3;
	}
	else if (ft_strcmp("siegel", str) == 0 || env->fractal == 4)
	{
		init_siegel(env, 1);
		env->fractal = 4;
	}
	else if (init_fractal2(env, str) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	*env;

	if (!(env = (t_mlx*)ft_memalloc(sizeof(t_mlx))) ||
		(!(env->img = (t_img*)ft_memalloc(sizeof(t_img)))))
		return (0);
	if (argc != 2 || init_fractal(env, argv[1]) != 1)
	{
		ft_putstr("./fractol mandelbrot\n./fractol julia\n./fractol lox\n");
		ft_putstr("./fractol siegel\n./fractol douady\n");
		ft_putstr("./fractol octopus\n./fractol tricorne\n");
		ft_putstr("./fractol burningship\n");
		free(env->img);
		free(env);
		return (0);
	}
	init(env);
	mlx_hook(env->wdw, 2, 3, key_funct, env);
	mlx_hook(env->wdw, 6, 7, julia_funct, env);
	mlx_mouse_hook(env->wdw, zoom_funct, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
