/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:31:22 by ssalor            #+#    #+#             */
/*   Updated: 2022/12/02 17:12:54 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbelem, size_t size)
{
	void	*pointer;

	pointer = malloc(nbelem * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, nbelem * size);
	return (pointer);
}
