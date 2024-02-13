/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:24 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 14:32:04 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(char const *format, ...);
int		ft_print_string(char *str);
int		ft_print_nbr_dec(int nbr);
int		ft_print_unsigned(unsigned int nbr);
/*funciones para hacer:
	-un write para cada tipo de dato (que entre void y se hará el cast, porque cuando no hay correlacion el resultado es indefinido)
	-un detector de formato contador
	-probablemente algo de conversion de bases
*/
#endif