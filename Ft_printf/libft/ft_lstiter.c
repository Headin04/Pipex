/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:59:28 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/28 14:18:22 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f != NULL)
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}	
	}
}
