/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:11:46 by marvin            #+#    #+#             */
/*   Updated: 2022/11/26 18:11:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	if (!dest)
		i = 0;
	else
		i = ft_strlen(dest);
	j = ft_strlen(src);
	if (n == 0)
		return (j);
	if (n <= i)
		j += n;
	else
		j += i;
	while (src[k] && i < n - 1)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = 0;
	return (j);
}
