/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:12:18 by ssalor            #+#    #+#             */
/*   Updated: 2023/07/03 11:14:48 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_final_sort(t_node **a, t_node **b)
{
	while (*b != NULL)
	{
		if (find_highest_node_location(*b) > (ps_stacklen(*b) / 2))
			ps_sort_finale_lower_half(a, b);
		else
			ps_sort_finale_upper_half(a, b);
	}
}