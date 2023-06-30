/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:15:24 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/30 13:17:09 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
