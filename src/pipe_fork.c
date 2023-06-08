/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:26:03 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/05/31 16:25:26 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    create_pipe(t_all *all)
{
    all->fd.pipe_result = pipe(all->fd.fd);

    if (all->fd.pipe_result == -1)
        return (perror("Error during the creation of the pipe"));
    all->fd.read_end = all->fd.fd[0];
    all->fd.write_end = all->fd.fd[1];
    // ft_printf("fd[0] == %i\n", all->fd.fd[0]);
    // ft_printf("fd[1] == %i\n", all->fd.fd[1]);
}

void    create_fork(t_all *all)
{
    // printf("yeaah\n");
    all->fd.pid = fork();
    if (all->fd.pid == -1)
    {
        perror("Error with the child process");
        exit(EXIT_FAILURE);
    }
    if (all->fd.pid == 0)
       child_behavior(all);
    all->fd.pid2 = fork();
    if (all->fd.pid2 == -1)
    {
        perror("Error with the child process");
        exit(EXIT_FAILURE);
    }
    if (all->fd.pid2 == 0)
        child2_behavior(all);
    else
        parents_behavior(all);
}