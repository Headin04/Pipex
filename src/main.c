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

void    path_in_lst(t_all *all)
{
    int i;
    char    **split;
    char    *dest;
    int     len;

    i = 0;
    split = ft_split(all->order.PATH, ':');
    while (split[i] != NULL)
    {
        len = ft_strlen(split[i]);
        dest = ft_strnjoin(split[i], "/", len);
        split[i] = dest;
        // dprintf(2, "i =====%d\n", i);
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
    all->order.nb_path = i -1;
    free(split);
    // print_lst(all->order.path_lst);
}

void    get_path(t_all *all)
{
    int i;

    i = 0;
    while (all->order.envp[i++] != NULL && all->order.PATH == NULL)
        all->order.PATH = ft_strnstr(all->order.envp[i], "PATH", 6);
    all->order.PATH = ft_strnstr(all->order.PATH, "/usr", ft_strlen(all->order.PATH));
    path_in_lst(all);
}

void    put_in_lst(t_all *all)
{
    int i;
    char    **split;

    i = 2;
    while (all->order.argv[i] != NULL)
    {
        split = ft_split(all->order.argv[i], ' ');
        ft_lstadd_backp(&all->order.lst, ft_lstnewp(split, NULL));
        ++i;
    }
    // free(split);
    // print_lst(all->order.lst);
}

int main(int argc, char **argv, char **envp)
{
    t_all   all;
    
    all.order.argv = argv;
    all.order.nb_cmd = argc - 3;
    all.order.lst = NULL;
    all.order.envp = envp;
    all.order.PATH = NULL;
    all.order.path_lst = NULL;
    if (argc < 5)
    {
        perror("Too many or not enough arguments");
        exit(EXIT_FAILURE);
    }
    put_in_lst(&all);
    get_path(&all);
    open_files1(&all);
    open_files2(&all);
    create_pipe(&all);
    create_fork(&all);
    close(all.fd.fd_file1);
    close(all.fd.fd_file2);
    ft_free_p(&all.order.lst);
    ft_free_p(&all.order.path_lst);
}