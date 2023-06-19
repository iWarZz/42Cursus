/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:17:48 by ssalor            #+#    #+#             */
/*   Updated: 2022/12/05 15:01:57 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ledebut(char const *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_lafin(char const *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strrchr(set, s1[ft_strlen(s1) - 1 - i]) == 0)
			break ;
		i++;
	}
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;
	size_t	fin;
	size_t	debut;

	i = 0;
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	debut = ft_ledebut(s1, set);
	fin = ft_lafin(s1, set);
	if (fin <= debut)
		return (ft_strdup(""));
	dest = malloc((fin - debut + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + debut, fin - debut + 1);
	return (dest);
}
