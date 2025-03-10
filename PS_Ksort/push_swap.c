/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/07 11:55:02 by dlopez-l         ###   ########.fr       */
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

char	**parse(int *argc, char **argv, t_data *data, int i)
{
	char	**new_argv;

	data->splitted = (*argc == 2);
	if (*argc == 1)
		return (NULL);
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

	split = parse(&argc, argv, &data, 1);
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
	}
	if (data.splitted)
		free_pptr(split, data.splitted);
	return (0);
}
