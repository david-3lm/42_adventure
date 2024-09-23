/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:33:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/23 11:33:48 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 500
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
	int			color_palette;
}				t_data;

t_complex	complex_mult(t_complex a, t_complex b);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_pow(t_complex a, int b);
t_complex	complex_pow2(t_complex a, int b);
t_complex	neg_pow(t_complex c, int p);
t_complex	exp_complex(t_complex z);
t_complex	calc_c(int x, int y, t_data data);
double		ft_atod(const char *c);
double		complex_abs(t_complex complex);
void		print_fractal(t_data *img);

/*MOVE AND ZOOM*/
int			move(int keycode, t_data *data);
void		zoom(t_data *d, int x, int y, double zoom);

/*DIFFERENT FRACTALS*/
int			mandelbrot(t_complex c);
int			multibrot(t_complex z, t_complex c);
int			julia(t_complex z, t_complex c);

/*ERROR*/
void		invalid_input(char *msg);

/*INIT*/
t_data		init_mlx(t_data data);

/*HOOKS*/
int			close_win(int keycode, t_data *vars);
int			hook_mouse(int button, int x, int y, t_data *mlx);
int			key_hook(int keycode, t_data *vars);
void		create_limits(t_data *data);

#endif