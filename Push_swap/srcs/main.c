/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:09:23 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/28 11:53:45 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("| Node %i:\n| val: %i\n----\n", stack->index, stack->value);
		stack = stack->next;
		if (stack->index == 1)
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**arg_values;

	a = NULL;
	b = NULL;
	arg_values = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		arg_values = ft_split(argv[1], ' ');
	else
		arg_values = argv + 1;
	create_stack(&a, arg_values);
	print_stack(a);
	sa(a);
	ft_printf("\n\n");
	print_stack(a);
}
