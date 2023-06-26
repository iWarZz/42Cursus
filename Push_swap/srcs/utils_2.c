/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:34:39 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/26 14:37:08 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	listdel_top(t_node **stack)
{
	t_node	*target_node;
	t_node	*second_node;

	target_node = *stack;
	if (target_node->next)
	{
		second_node = target_node->next;
		second_node->prev = NULL;
		*stack = second_node;
	}
	else
		*stack = NULL;
	free(target_node);
}

void	listdel_bottom(t_node **stack)
{
	t_node	*target_node;
	t_node	*prev_node;

	target_node = get_last_node(*stack);
	prev_node = target_node->prev;
	target_node->prev = NULL;
	prev_node->next = NULL;
	free(target_node);
}
