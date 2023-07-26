/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:00:19 by ssalor            #+#    #+#             */
/*   Updated: 2023/07/25 14:09:31 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_big_sort(t_node **a, t_node **b, int a_len)
{
	int	chunk_len;
	int	chunk_nbr;

	chunk_len = 65;
	if (a_len <= 100)
		chunk_len = 20;
	chunk_nbr = 1;
	while (*a)
	{
		if ((*a)->index <= (chunk_nbr * chunk_len))
		{
			(*a)->chunk = chunk_nbr;
			if ((*a)->index >= ((chunk_nbr * chunk_len) - (chunk_len / 2)))
			{
				pb(a, b);
				rb(b);
			}
			else
				pb(a, b);
		}
		else
			ra(a);
		if (ps_stacklen(*b) == (chunk_nbr * chunk_len))
			chunk_nbr++;
	}
}

void	ps_mid_sort(t_node **a, t_node **b)
{
	while (ps_stacklen(*a) > 3)
	{
		if (find_high_index_node(*a) == *a)
			pb(a, b);
		else
			ra(a);
	}
	if (!ps_is_sorted(*a))
		ps_small_sort(a);
	if (!ps_is_sorted(*b))
		sb(*b);
	while (*b)
	{
		pa(a, b);
		ra(a);
	}
}

void	ps_small_sort(t_node **a)
{
	t_node	*high_node;

	high_node = find_high_index_node(*a);
	if (*a == high_node)
		ra(a);
	else if ((*a)->next == high_node)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(*a);
}

void	ps_sort(t_node **a, t_node **b)
{
	int	a_len;

	a_len = ps_stacklen(*a);
	if (a_len == 1 || ps_is_sorted(*a))
		return ;
	else if (a_len == 2)
		sa(*a);
	else if (a_len == 3)
		ps_small_sort(a);
	else if (a_len == 4 || a_len == 5)
		ps_mid_sort(a, b);
	else
	{
		ps_big_sort(a, b, a_len);
		ps_final_sort(a, b);
	}
	return ;
}
