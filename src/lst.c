/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:21:49 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/15 18:19:39 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_in_lst(t_all *all)
{
	int		i;
	char	**split;
	char	*dest;
	int		len;

	i = 0;
	split = ft_split(all->order.path, ':');
	while (split[i] != NULL)
	{
		len = ft_strlen(split[i]);
		dest = ft_strnjoin(split[i], "/", len);
		split[i] = dest;
		++i;
	}
	i = 0;
	if (all->order.argv[i][0] == '/')
		i++;
	while (split[i] != NULL)
	{
		ft_lstadd_backp(&all->order.path_lst, ft_lstnewp(NULL, split[i]));
		++i;
	}
	all->order.nb_path = i - 1;
	free(split);
}

void	get_path(t_all *all)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (all->order.envp[i++] != NULL && all->order.path == NULL)
		all->order.path = ft_strnstr(all->order.envp[i], "PATH", 6);
	size = ft_strlen(all->order.path);
	all->order.path = ft_strnstr(all->order.path, "/usr", size);
	path_in_lst(all);
}

void	put_in_lst(t_all *all)
{
	int		i;
	char	**split;

	i = 2;
	while (all->order.argv[i] != NULL)
	{
		split = ft_split(all->order.argv[i], ' ');
		ft_lstadd_backp(&all->order.lst, ft_lstnewp(split, NULL));
		++i;
	}
}
