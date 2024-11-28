/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:33:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/26 20:18:02 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 4000
# define HEIGHT 2000
# define MAX_ITER 50
# define BAD_INPUT "\033[1;31m Bad input!\033[0m\n To execute the fractal: \n\t \
- Julia: ./fractol julia [(double)cR] [(double)cI] \n\t \
\033[1;31m- Mandelbrot: ./fractol\033[1;32m  mandel \n\t \
\033[1;31m- Multibrot: ./fractol\033[1;32m multi [(double)cR] [(double)cI] ([(int)pow]) \n\t \
\033[1;31m- Phoenix: ./fractol\033[1;32m \
phoenix [(double)cR] [(double)cI] [(double)pR] [(double)pI]"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

typedef struct s_data
{
	int			fractal;
	void		*img;
	void		*mlx;
	void		*win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			iter;
	t_complex	max_c;
	t_complex	min_c;
	t_complex	c_juila;
	t_complex	p_pho;
	int			multi_pow;
	int			color_palette;
}				t_data;

t_complex	complex_mult(t_complex a, t_complex b);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_pow(t_complex a, int b);
t_complex	neg_pow(t_complex c, int p);
t_complex	calc_c(int x, int y, t_data data);
double		ft_atod(const char *c);
double		complex_abs(t_complex complex);
void		print_fractal(t_data *img);

/*MOVE AND ZOOM*/
void		move(int keycode, t_data *data, double mov);
void		zoom(t_data *d, int x, int y, double zoom);

/*DIFFERENT FRACTALS*/
int			mandelbrot(t_complex c, t_data data);
int			multibrot(t_complex z, t_data data);
int			julia(t_complex z, t_data data);
int			phoenix(t_complex c, t_data data);

/*ERROR*/
void		invalid_input(char *msg);
int			close_win(t_data *vars);

/*RENDER*/
int			get_color(int iter, int cp, t_data data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw(t_data *img, t_complex c, int x, int y);
void		print_fractal(t_data *img);
void		key_color(int keycode, t_data *vars);
void		key_zoom(int keycode, t_data *vars);
void		key_iter(int keycode, t_data *vars);

/*INIT*/
t_data		init_mlx(t_data data);
int			get_input(t_data *data, int argc, char **args);

/*HOOKS*/
int			hook_mouse(int button, int x, int y, t_data *mlx);
int			key_hook(int keycode, t_data *vars);
void		create_limits(t_data *data);

#endif