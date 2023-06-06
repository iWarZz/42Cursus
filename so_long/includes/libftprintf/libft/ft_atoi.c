/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:15:25 by ssalor            #+#    #+#             */
/*   Updated: 2022/12/02 15:31:00 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sn;
	int	res;
	int	o;

	o = 0;
	res = 0;
	sn = 1;
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		o++;
		if (o >= 2)
			return (0);
		if (nptr[i] == '-')
			sn *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
		res = res * 10 + nptr[i++] - '0';
	return (res * sn);
}
