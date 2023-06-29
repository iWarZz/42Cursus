/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:42:51 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/29 14:55:15 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (stack == NULL)
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
