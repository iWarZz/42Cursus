/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:42:51 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/26 13:26:28 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotary_please(t_node **a)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = *a;
	last_node = get_last_node(*a);
	first_node->prev = last_node;
	last_node->next = first_node;
}

t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	listadd_bottom(t_node **a, int value)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		exit(ft_printf(MAL_ER));
	new_node->value = value;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->index = 1;
	}
	else
	{
		last_node = get_last_node(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->index = last_node->index + 1;
	}
}

void	listadd_top(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*first_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		exit(ft_printf(MAL_ER));
	new_node->value = value;
	if (*stack != NULL)
	{
		first_node = *stack;
		new_node->next = first_node;
		first_node->prev = new_node;
	}
	*stack = new_node;
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
			exit(ft_printf(ARG_NOT_INT));
		check_rep(*a, (int)value);
		listadd_bottom(a, (int)value);
		i++;
	}
	rotary_please(a);
}
