/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:55:41 by ssalor            #+#    #+#             */
/*   Updated: 2023/02/14 14:59:56 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2, size_t s1_len, size_t s2_len)
{
	char	*str;
	size_t	i;

	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		++i;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*ft_newline(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (str);
			++str;
		}
	}
	return (NULL);
}

int	ft_strlen(const char *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a[i] != '\0')
		++i;
	return (i);
}
