/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:45:25 by marvin            #+#    #+#             */
/*   Updated: 2022/11/26 18:45:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)c)
			return (&((char *)string)[i]);
		i++;
	}
	if ((char)c == string[i])
		return (&((char *)string)[i]);
	return (NULL);
}
