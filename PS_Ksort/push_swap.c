/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/04 11:38:21 by dlopez-l         ###   ########.fr       */
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
	char	**new_argv;
	int		i;

	if (*argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		*argc = count_args(new_argv);
	}
	else if (*argc > 2)
	{
		new_argv = ft_calloc((*argc), sizeof(char *));
		if (!new_argv)
			return (NULL);
		i = 1;
		while (i < *argc)
		{
			new_argv[i - 1] = argv[i];
			i++;
		}
		new_argv[*argc - 1] = NULL;
		(*argc)--;
	}
	else
		new_argv = argv;
	return (new_argv);
}

int	main(int argc, char **argv)
{
	t_data	data;

	argv = parse(&argc, argv);
	if (argc >= 1)
	{
		data.stack_a = ft_calloc(argc, sizeof(t_number));
		data.stack_b = ft_calloc(argc, sizeof(t_number));
		if (!data.stack_a || !data.stack_b)
			free_data(&data);
		if (!init_a(&data, argc, argv))
			print_error();
		else if (argc == 2)
			order_two(&data);
		else if (argc == 3)
			order_three(&data);
		else if (argc == 4)
			order_four(&data);
		else if (argc >= 5)
			start_algo(&data);
		free_data(&data);
		free_pptr(argv);
	}
	return (0);
}
