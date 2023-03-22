/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:30:37 by ssalor            #+#    #+#             */
/*   Updated: 2023/03/21 15:24:25 by ssalor           ###   ########.fr       */
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
