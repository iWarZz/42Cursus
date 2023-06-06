/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:30:37 by ssalor            #+#    #+#             */
/*   Updated: 2022/11/30 17:30:39 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *a, int b, size_t length)
{
	size_t	i;

	i = 0;
	while (i != length)
	{
		((unsigned char *)a)[i] = (unsigned char)b;
		i++;
	}
	return (a);
}
/*
int main()
{
    char test[] = "test";
    int    c = 65;
    printf("ft_memset: %s\n", ft_memset(test, c, 2));
    printf("memset: %s\n", memset(test, c, 2));

    // Both should output "AAst"
}*/
