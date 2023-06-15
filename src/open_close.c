/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:25:36 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/06/15 16:54:12 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files1(t_all *all)
{
	all->fd.fd_file1 = open(all->order.argv[1], O_RDONLY);
	if (all->fd.fd_file1 == -1)
	{
		perror("Error during the opening of file 1");
		exit(EXIT_FAILURE);
	}
}

void	open_files2(t_all *all)
{
	all->fd.fd_file2 = open(all->order.argv[all->order.nb_cmd + 2], O_CREAT
			| O_TRUNC | O_RDWR, 0644);
	if (all->fd.fd_file2 == -1)
	{
		perror("Error during the opening of file 2");
		exit(EXIT_FAILURE);
	}
}

void	ft_free_p(t_list_p **lst)
{
	t_list_p	*tmp;
	int			i;

	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->content != NULL)
		{
			i = 0;
			while ((*lst)->content[i] != NULL)
			{
				free((*lst)->content[i]);
				i++;
			}
			free((*lst)->content);
		}
		free((*lst)->pcontent);
		free(*lst);
		*lst = tmp;
	}
}

void	end(t_all *all)
{
	close(all->fd.fd_file1);
	close(all->fd.fd_file2);
	ft_free_p(&all->order.lst);
	ft_free_p(&all->order.path_lst);
}
