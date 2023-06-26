/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:55:25 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/26 12:02:50 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_reverse_rotate(t_node **stack)
{
	listadd_top(stack, get_last_node((*stack)->value));
	listdel_bottom(stack);
}

void	rra(t_node **a)
{
	if (*a)
	{
		ps_reverse_rotate(a);
		ft_printf("rra\n");
	}
}

void	rrb(t_node **b)
{
	if(*b)
	{
		ps_reverse_rotate(b);
		ft_printf("rrb\n");
	}
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
