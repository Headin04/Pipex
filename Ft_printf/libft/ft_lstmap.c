/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:18:40 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/29 12:39:45 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_bis;
	t_list	*tmp;

	lst_bis = NULL;
	tmp = lst;
	while (lst != NULL && tmp != NULL)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp != NULL)
			ft_lstadd_back(&lst_bis, tmp);
		else
			ft_lstclear(&tmp, del);
		lst = lst->next;
	}
	return (lst_bis);
}
