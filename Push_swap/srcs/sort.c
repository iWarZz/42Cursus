/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:00:19 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/29 16:17:37 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_small_sort(t_node *a)
{
	
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
}
