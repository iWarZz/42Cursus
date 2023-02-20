/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:12:42 by marvin            #+#    #+#             */
/*   Updated: 2022/11/28 16:01:49 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*int main()
{
    char ft_str[] = "aaabaa";
    int ft_b = 'b';
    printf("ft_memchr: %p\n", ft_memchr(ft_str, ft_b, 4));

    char str[] = "aaacaa";
    int b = 'b';
    printf("memchr: %p\n", memchr(str, b, 4));
}*/