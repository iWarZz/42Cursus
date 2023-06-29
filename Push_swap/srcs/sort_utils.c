/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:15:24 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/29 15:58:32 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_small_sort(t_node *a)
{
	
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
