/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:50:37 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/26 14:36:53 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_rotate(t_node **stack)
{
	listadd_bottom(stack, (*stack)->value);
	listdel_top(stack);
}

void	ra(t_node **a)
{
	if (*a)
	{
		ps_rotate(a);
		ft_printf("ra\n");
	}
}

void	rb(t_node **b)
{
	if (*b)
	{
		ps_rotate(b);
		ft_printf("rb\n");
	}
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
