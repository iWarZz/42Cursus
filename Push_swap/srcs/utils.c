/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:42:51 by ssalor            #+#    #+#             */
/*   Updated: 2023/07/03 11:56:31 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_last_node(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	listadd_bottom(t_node **stack, int value, int index, int chunk_nbr)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		exit(write(2, "Error\n", 6));
	new_node->value = value;
	new_node->index = index;
	new_node->chunk = chunk_nbr;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	listadd_top(t_node **stack, int value, int index, int chunk_nbr)
{
	t_node	*new_node;
	t_node	*first_node;

	new_node = ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		exit(write(2, "Error\n", 6));
	new_node->value = value;
	new_node->chunk = chunk_nbr;
	new_node->index = index;
	if (*stack != NULL)
	{
		first_node = *stack;
		new_node->next = first_node;
		first_node->prev = new_node;
	}
	*stack = new_node;
}

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
