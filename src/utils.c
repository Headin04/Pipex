/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:11:21 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/05/31 15:45:13 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list_p	*ft_lstnewp(char **content, char *pcontent)
{
	t_list_p	*new;

	new = (t_list_p *)malloc(sizeof(t_list_p));
	if (new != NULL)
	{
		new->content = content;
		new->pcontent = pcontent;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

void	ft_lstadd_backp(t_list_p **lst, t_list_p *new)
{
	t_list_p	*last;

	last = *lst;
	if (new != NULL)
	{
		if (*lst != NULL)
		{
			while (last->next != NULL)
				last = last->next;
			last->next = new;
		}
		else
			*lst = new;
	}
}
/*void	print_lst(t_list_p *lst)
{
	// int	i;

	// i = 0;
		while (lst != NULL)
		{
			printf("lst == %s\n", lst->pcontent);
            // if (lst->content[1] != NULL)
            //     printf("lst2 == %s\n", lst->content[1]);
			// i++;
			lst = lst->next;
		}
}*/
