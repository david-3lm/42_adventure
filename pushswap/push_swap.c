/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/15 15:57:06 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	**parse(int *argc, char **argv)
{
	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		*argc = count_args(argv);
	}
	return (argv);
}

int	main(int argc, char **argv)
{
	t_data	data;

	argv = parse(&argc, argv);
	if (argc > 1)
	{
		data.stack_a = ft_calloc(argc, sizeof(int));
		data.stack_b = ft_calloc(argc, sizeof(int));
		if (!data.stack_a || !data.stack_b)
			free_data(data);
		if (!init_a(&data, argc, argv))
			print_error();
		else if (argc == 3)
			order_two(&data);
		else if (argc == 4)
			order_three(&data);
		else if (argc == 5)
			order_four(&data);
		else if (argc >= 6)
			start_algo(&data);
		free_data(data);
	}
	return (0);
}
