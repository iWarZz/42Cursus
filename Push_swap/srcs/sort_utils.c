/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:15:24 by ssalor            #+#    #+#             */
/*   Updated: 2023/07/03 11:25:44 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_highest_node_location(t_node *stack)
{
	int	highest_index;
	int	runner;
	int	highest_location;

	highest_index = 0;
	runner = 1;
	while (stack)
	{
		if (stack->index > highest_index)
		{
			highest_index = stack->index;
			highest_location = runner;
		}
		runner++;
		stack = stack->next;
	}
	return (highest_location);
}

int	find_second_highest_node_location(t_node *stack)
{
	int	second_highest_index;
	int	runner;

	second_highest_index = find_high_index_node(stack)->index - 1;
	runner = 1;
	while (stack && second_highest_index > 0)
	{
		if (stack->index == second_highest_index)
			return (runner);
		runner++;
		stack = stack->next;
	}
	return (0);
}


t_node	*find_high_index_node(t_node *stack)
{
	int		high_index;
	t_node	*high_node;

	high_index = 1;
	while (stack)
	{
		if (stack->index > high_index)
		{
			high_index = stack->index;
			high_node = stack;
		}
		stack = stack->next;
	}
	return (high_node);
}

int		ps_is_sorted(t_node *stack)
{
	while (stack)
	{
		if (stack->next)
		{
			if (stack->index > stack->next->index)
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int		ps_stacklen(t_node *stack)
{
	int		i;

	i = 1;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
