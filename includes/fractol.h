/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:58:08 by arive-de          #+#    #+#             */
/*   Updated: 2019/01/31 13:39:21 by arive-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <mlx.h>
# include "math.h"
# include <stdio.h>

# define WDW_WIDTH 800
# define WDW_HEIGHT 600

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	int			fractal;
	int			x;
	int			y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		i;
	double		zoom;
	double		zoom_x;
	double		zoom_y;
	int			iter_max;
	int			img_x;
	int			img_y;
	int			color;
	void		*mlx_ptr;
	void		*wdw;
	t_img		*img;

}				t_mlx;

/*
 **		tools.c
*/

void			init(t_mlx *env);
void			img_to_wdw(t_mlx *env);
void			draw(int x, int y, int color, t_mlx *env);
int				key_funct(int key, t_mlx *env);
int				julia_funct(int x, int y, t_mlx *env);
int				zoom_funct(int key, int x, int y, t_mlx *env);

/*
 **		mandelbrot.c
*/

void			init_mandelbrot(t_mlx *env, int part);
void			exe_mandelbrot(t_mlx *env);

/*
 **		julia.c
*/

void			init_julia(t_mlx *env, int part);
void			exe_julia(t_mlx *env);

/*
 **		lox.c
*/

void			init_lox(t_mlx *env, int part);
void			exe_lox(t_mlx *env);

/*
 **		tricorne.c
*/

void			init_tricorne(t_mlx *env, int part);
void			exe_tricorne(t_mlx *env);

/*
 **		octopus.c
*/

void			init_octopus(t_mlx *env, int part);
void			exe_octopus(t_mlx *env);
/*
 **		siegel.c
*/

void			init_siegel(t_mlx *env, int part);
void			exe_siegel(t_mlx *env);

/*
 **		douady.c
*/

void			init_douady(t_mlx *env, int part);
void			exe_douady(t_mlx *env);

/*
 **		burningship.c
*/

void			init_burningship(t_mlx *env, int part);
void			exe_burningship(t_mlx *env);

/*
 **		main.c
*/

int				which_fract(t_mlx *env, char *str);
int				main(int argc, char **argv);

#endif
