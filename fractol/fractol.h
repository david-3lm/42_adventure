/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:33:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/29 19:28:40 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 50
# define K_ESC 65307
# include <math.h>
# include <mlx.h>

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}				t_complex;

t_complex	complex_mult(t_complex a, t_complex b);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	calc_c(int x, int y);
double		complex_abs(t_complex complex);
int			hook_mouse(int button, int x, int y, t_data *mlx);


#endif