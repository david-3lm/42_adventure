/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:33:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/09 16:59:32 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 50
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	off_x;
	double	off_y;
	double	zoom;
	t_complex	max_c;
	t_complex	min_c;
}				t_data;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

t_complex	complex_mult(t_complex a, t_complex b);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	calc_c(int x, int y, t_data data);
double		complex_abs(t_complex complex);
int			hook_mouse(int button, int x, int y, t_data *mlx);
void		print_fractal(t_data *img);

/*MOVE AND ZOOM*/
int			move(int keycode, t_data *data);

#endif