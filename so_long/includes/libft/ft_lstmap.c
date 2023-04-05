/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:45:59 by ssalor            #+#    #+#             */
/*   Updated: 2022/12/13 14:00:03 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*top;
	void	*temp;

	new = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		top = ft_lstnew(temp);
		if (!top)
		{
			free (temp);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, top);
		lst = lst->next;
	}
	return (new);
}
