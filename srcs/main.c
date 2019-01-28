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

void	launch_fractal(t_mlx *env)
{
	if (env->fractal == 1)
		exe_mandelbrot(env);
	else if (env->fractal == 2)
		exe_julia(env);
	else if (env->fractal == 3)
		exe_fern(env);
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

void	init(t_mlx *env)
{
	env->mlx_ptr = mlx_init();
	env->wdw = mlx_new_window(env->mlx_ptr, WDW_WIDTH, WDW_HEIGHT, "Fractol");
	img_to_wdw(env);
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
	else if (ft_strcmp("fern", str) == 0 || env->fractal == 3)
	{
		init_fern(env);
		env->fractal = 3;
	}
	else
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
		printf("TODO : print usage\n"); // FREE
		return (0);
	}
	init(env);
	mlx_hook(env->wdw, 2, 3, key_funct, env);
	mlx_hook(env->wdw, 6, 7, julia_funct, env); //mouse changing for julia
	mlx_mouse_hook(env->wdw, zoom_funct, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
