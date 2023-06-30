/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:00:19 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/30 13:31:08 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_mid_sort(t_node **a, t_node **b)
{
	
}

void	ps_small_sort(t_node **a)
{
	t_node	*high_node;

	high_node = find_high_index_node(*a);
	if (*a == high_node)
		ra(*a);
	else if ((*a)->next == high_node)
		rra(*a);
	if ((*a)->index > (*a)->next->next)
		sa(*a);
}

void	ps_sort(t_node **a, t_node **b)
{
	int	a_len;

	a_len = ps_stacklen(*a);
	if (a_len == 1 || ps_is_sorted(*a))
		return ;
	else if (a_len == 2)
		sa(a);
	else if (a_len == 3)
		ps_small_sort(*a);
	else if (a_len == 4 || a_len == 5)
		ps_mid_sort(*a, *b);
}
