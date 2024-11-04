/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/04 23:51:39 by dlopez-l         ###   ########.fr       */
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

char	**parse(int *argc, char **argv, t_data *data)
{
	char	**new_argv;
	int		i;

	data->splitted = (*argc == 2);
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
	return (new_argv);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**split;

	if (argc != 1)
		split = parse(&argc, argv, &data);
	if (argc >= 1 && split)
	{
		data.stack_a = ft_calloc(argc, sizeof(t_number));
		data.stack_b = ft_calloc(argc, sizeof(t_number));
		if (!data.stack_a || !data.stack_b)
			free_data(&data);
		if (!init_a(&data, argc, split))
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
		free_pptr(split, data.splitted);
	}
	return (0);
}
