/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:04:16 by ssalor            #+#    #+#             */
/*   Updated: 2023/06/06 14:15:27 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compte_mot(char const *s, char c)
{
	size_t	i;
	size_t	compteur;

	compteur = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			compteur++;
		i++;
	}
	return (compteur);
}

void	ft_ecris(char *dest, const char *src, char c)
{
	size_t	i;

	i = 0;
	while ((src[i] == c || src[i] == '\0') == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_marchepas(char **tab, int k)
{
	while (k)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
	return (-1);
}

int	ft_tabtab(char **tab, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((s[i + j] == c || s[i + j] == '\0') == 0)
				j++;
			tab[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!tab)
				return (ft_marchepas(tab, k));
			ft_ecris(tab[k], s + i, c);
			i += j;
			k++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_compte_mot(s, c) + 1));
	if (!tab)
		return (NULL);
	tab[ft_compte_mot(s, c)] = 0;
	ft_tabtab(tab, s, c);
	return (tab);
}
