/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:04:37 by ssalor            #+#    #+#             */
/*   Updated: 2023/02/03 13:07:19 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_search_format(va_list args, const char format)
{
	int	compteur;

	compteur = 0;
	if (format == 'c')
		compteur += ft_printchar(va_arg (args, int));
	if (format == 's')
		compteur += ft_printstr(va_arg(args, char *));
	if (format == 'p')
		compteur += ft_print_ptr(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		compteur += ft_printnbr(va_arg(args, int));
	if (format == 'u')
		compteur += ft_print_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		compteur += ft_print_hexa(va_arg(args, unsigned int), format);
	if (format == '%')
		compteur += write(1, "%", 1);
	return (compteur);
}

int	ft_printf(const char *str, ...)
{
	int		compteur;
	int		i;
	va_list	args;

	i = 0;
	compteur = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			compteur += ft_search_format(args, str[i + 1]);
			i++;
		}
		else
			compteur += ft_printchar(str[i]);
		i++;
	}
	va_end (args);
	return (compteur);
}
