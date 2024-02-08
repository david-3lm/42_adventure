/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:09:24 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/08 20:02:14 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);
/*funciones para hacer:
	-un write para cada tipo de dato (que entre void y se hará el cast, porque cuando no hay correlacion el resultado es indefinido)
	-un detector de formato contador
	-probablemente algo de conversion de bases
*/
#endif