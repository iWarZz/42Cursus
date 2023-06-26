/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:58:28 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/26 14:36:08 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_push(t_node **stack_src, t_node **stack_dest)
{
	listadd_top(stack_dest, (*stack_src)->value);
	listdel_top(stack_src);
}

void	pa(t_node **a, t_node **b)
{
	if (*b)
	{
		ps_push(b, a);
		ft_printf("pa\n");
	}
}

void	pb(t_node **a, t_node **b)
{
	if (*a)
	{
		ps_push(a, b);
		ft_printf("pb\n");
	}
}
