/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arive-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:58:08 by arive-de          #+#    #+#             */
/*   Updated: 2018/04/16 15:33:37 by arive-de         ###   ########.fr       */
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
	int x;
	int y;
	double x1;
	double x2;
	double y1;
	double y2;
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double tmp;
	double i;
	double zoom;
	double zoom_x;
	double zoom_y;
	int iter_max;
	int img_x;
	int img_y;
	int color;
	void		*mlx_ptr;
	void		*wdw;
	t_img		*img;

}				t_mlx;

/*
 **		tools.c
*/

void	init(t_mlx *env);
void	img_to_wdw(t_mlx *env);
void	draw(int x, int y, int color, t_mlx *env);

/*
 **		mandelbrot.c
*/

void	init_mandelbrot(t_mlx *env, int part);
void	exec_mandelbrot(t_mlx *env);

/*
 **		julia.c
*/

void	init_julia(t_mlx *env, int part);
void	exec_julia(t_mlx *env);

/*
 **		main.c
*/

int		which_fract(t_mlx *env, char *str);
int		main(int argc, char **argv);



#endif
