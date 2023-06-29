/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:09:23 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/29 15:02:57 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("| Node %i:\n| val: %i\n----\n", stack->index, stack->value);
		stack = stack->next;
		if (stack->index == 1)
			break ;
	}
}*/
/* tant que a :	remonte dans a avec runner->prev.
				puis index en parcourant runner*/
void	set_index(t_node *a)
{
	int		i;
	t_node	*runner;

	while (a)
	{
		runner = a;
		i = 1;
		while (runner->prev)
			runner = runner->prev;
		while (runner)
		{
			if (a->value < runner->value)
				i++;
			runner = runner->next;
		}
		a->index = i;
		a = a->next;
	}
}

void	create_stack(t_node **a, char **arg_values)
{
	long	value;
	int		i;

	i = 0;
	while (arg_values[i])
	{
		check_syntax(arg_values[i]);
		value = ft_atol(arg_values[i]);
		if (value > INT_MAX || value < INT_MIN)
			exit(write(2, "Error\n", 6));
		check_rep(*a, (int)value);
		listadd_bottom(a, (int)value, 0, 0);
		i++;
	}
	set_index(a);
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
	ps_sort(a, b);
	//print_stack(a);
	//ft_printf("\n\n");
	//print_stack(a);
}
