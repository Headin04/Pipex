/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:45:34 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/05/31 16:28:36 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_all *all)
{
	put_in_lst(all);
	get_path(all);
	open_files1(all);
	open_files2(all);
	create_pipe(all);
	create_fork(all);
}

void	all_initialization(int argc, char **argv, char **envp, t_all *all)
{
	all->order.argv = argv;
	all->order.nb_cmd = argc - 3;
	all->order.envp = envp;
	all->order.lst = NULL;
	all->order.PATH = NULL;
	all->order.path_lst = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_all	all;

	all_initialization(argc, argv, envp, &all);
	if (argc < 5)
	{
		perror("Too many or not enough arguments");
		exit(EXIT_FAILURE);
	}
	pipex(&all);
	end(&all);
}
