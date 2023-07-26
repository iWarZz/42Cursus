/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:12:18 by ssalor            #+#    #+#             */
/*   Updated: 2023/07/26 15:18:51 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort_final(t_node **a, t_node **b)
{
	while (*b != NULL)
	{
		if (find_highest_node_location(*b) > (ps_stacklen(*b) / 2))
			ps_sort_finale_lower_half(a, b);
		else
			ps_sort_finale_upper_half(a, b);
	}
}

void	ps_sort_finale_lower_half(t_node **a, t_node **b)
{
	bool	second_found;

	while (find_highest_node_location(*b) != 1)
	{
		if (find_second_highest_node_location(*b) == 1)
		{
			pa(a, b);
			second_found = true;
		}
		else
			rrb(b);
	}
	pa(a, b);
	if (second_found)
	{
		sa(*a);
		second_found = false;
	}
}

void	ps_sort_finale_upper_half(t_node **a, t_node **b)
{
	bool	second_found;

	while (find_highest_node_location(*b) != 1)
	{
		if (find_second_highest_node_location(*b) == 1)
		{
			pa(a, b);
			second_found = true;
		}
		else
			rb(b);
	}
	pa(a, b);
	if (second_found)
	{
		sa(*a);
		second_found = false;
	}
}
