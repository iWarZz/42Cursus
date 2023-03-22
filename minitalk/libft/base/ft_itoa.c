/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:15:35 by ssalor            #+#    #+#             */
/*   Updated: 2022/12/06 14:25:30 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nadege(long m, char *dest, size_t *len)
{
	if (m > 9)
	{
		ft_nadege(m / 10, dest, len);
		ft_nadege(m % 10, dest, len);
	}
	if (m <= 9)
		dest[(*len)++] = m + '0';
}

int	ft_compte(long m)
{
	size_t	compteur;

	compteur = 0;
	if (m == 0)
		compteur++;
	if (m < 0)
	{
		m = -m;
		compteur++;
	}
	while (m > 0)
	{
		m = m / 10;
		compteur++;
	}
	return (compteur);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*dest;
	long	m;

	len = 0;
	m = n;
	dest = malloc(sizeof(char) * (ft_compte(m) + 1));
	if (!dest)
		return (NULL);
	if (m < 0)
	{
		dest[len] = '-';
		m = -m;
		len++;
	}
	ft_nadege(m, dest, &len);
	dest[len] = '\0';
	return (dest);
}
