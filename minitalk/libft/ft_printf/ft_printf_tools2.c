/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:49:54 by ssalor            #+#    #+#             */
/*   Updated: 2023/01/20 13:53:10 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_utoa(n);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
