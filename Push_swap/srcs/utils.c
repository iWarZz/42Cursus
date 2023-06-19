/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:42:51 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/19 14:32:17 by ssalor           ###   ########.fr       */
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
		if(!(*str >= '0' && *str <= '9'))
			exit(ft_printf(ER_SYNT));
		str++;
	}
}

void	create_stack(t_node **a, char **arg_values)
{
	long	value;
	int		i;

	i = 0;
	while (arg_values[i])
	{
		check_syntax(arg_values[i]);
		value = ft_atol(arg_values[i]);
		if (value > INT_MAX || value < INT_MIN)
			exit(ft_printf(ARG_NO_INT));
		check_rep(*a, (int)value);
	}
}
