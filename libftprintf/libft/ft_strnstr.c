/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:14:47 by ssalor            #+#    #+#             */
/*   Updated: 2022/11/30 17:06:36 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *grand, const char *petit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (petit[0] == '\0' || (!grand && len == 0))
		return ((char *)grand);
	while (i < len && grand[i])
	{
		j = 0;
		if (grand[i] == petit[j])
		{
			while (grand[i + j] == petit[j] && petit[j] && (i + j) < len)
			{
				j++;
			}
			if (petit[j] == '\0')
				return ((char *)&grand[i]);
		}
		i++;
	}
	return (NULL);
}
