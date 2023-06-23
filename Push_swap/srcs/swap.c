/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:05:06 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/23 14:17:23 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_swap(t_node *stack)
{
	int	temp;

	if (stack == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	sa(t_node *a)
{
	if (a == NULL && a->next != NULL)
	{
		ps_swap(a);
		ft_printf("sa\n");
	}
}

void	sa(t_node *b)
{
	if (b == NULL && b->next != NULL)
	{
		ps_swap(b);
		ft_printf("sa\n");
	}
}

void	ss(t_node *a, t_node *b)
{
	sa(a);
	sb(b);
}
