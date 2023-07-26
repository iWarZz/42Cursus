/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:15:24 by ssalor            #+#    #+#             */
/*   Updated: 2023/07/26 15:15:35 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_is_sorted(t_node *stack)
{
	while (stack)
	{
		if (stack->next)
			if (stack->index > stack->next->index)
				return (0);
		stack = stack->next;
	}
	return (1);
}

t_node	*find_highest_index_node(t_node *stack)
{
	int		highest_index;
	t_node	*highest_node;

	highest_index = 1;
	while (stack)
	{
		if (stack->index > highest_index)
		{
			highest_index = stack->index;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

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

	second_highest_index = find_highest_index_node(stack)->index - 1;
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

int	ps_stacklen(t_node *stack)
{	
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
