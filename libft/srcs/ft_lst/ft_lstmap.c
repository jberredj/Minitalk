/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:06:25 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 13:03:43 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

static void	*ft_lstmap_clean(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = NULL;
	new_list = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		if (tmp == NULL)
			return (ft_lstmap_clean(&new_list, del));
		new_elem = ft_lstnew(tmp);
		if (new_elem == NULL)
		{
			del(tmp);
			return (ft_lstmap_clean(&new_list, del));
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
