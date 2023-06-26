/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:02:29 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/26 14:35:10 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_rep(t_node *a, int value)
{
	if (a == NULL)
		return ;
	while (a)
	{
		if (a->value == value)
			exit(ft_printf(ARG_REP));
		a = a->next;
	}
}

void	check_syntax(char *str)
{
	if (!str || *str == '\0')
		exit(ft_printf(ER_SYNT));
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		exit(ft_printf(ER_SYNT));
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			exit(ft_printf(ER_SYNT));
		str++;
	}
}
