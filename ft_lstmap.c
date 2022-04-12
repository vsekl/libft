/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:50:51 by vjose             #+#    #+#             */
/*   Updated: 2021/10/11 15:50:51 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != 0)
	{
		if (lst->content != NULL)
		{
			tmp = ft_lstnew(f(lst->content));
			ft_lstadd_back(&new_lst, tmp);
		}
		else
			ft_lstclear(&new_lst, del);
		lst = lst->next;
	}
	return (new_lst);
}
