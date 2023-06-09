/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:45:00 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/05/31 16:24:44 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include "../Ft_printf/ft_printf.h"
# include "../Ft_printf/libft/libft.h"

typedef struct s_list_p
{
	char			**content;
	char			*pcontent;
	struct s_list_p	*next;
}	t_list_p;

typedef struct s_order
{
	char			**argv;
	char			**envp;
	char			*PATH;
	t_list_p		*path_lst;
	t_list_p		*path_lst_start;
	t_list_p		*lst;
	int				nb_path;
	int				nb_cmd;
	char			*command[];
}	t_order;

typedef struct	s_fd
{
	int				fd[2];
	int				fd_file1;
	int				fd_file2;
	int				pipe_result;
	int				read_end;
	int				write_end;
	pid_t			pid;
	pid_t			pid2;
}	t_fd;

typedef struct	s_all
{
	t_fd			fd;
	t_order			order;
}	t_all;

    /*UTILS*/
t_list_p	*ft_lstnewp(char **content, char *pcontent);
void		ft_lstadd_backp(t_list_p **lst, t_list_p *new);
void		print_lst(t_list_p *lst);

    /*OPEN_CLOSE*/
void		open_files1(t_all *all);
void		open_files2(t_all *all);
void		create_pipe(t_all *all);
void		create_fork(t_all *all);
void		ft_free_p(t_list_p **lst);
void		end(t_all *all);

    /*BEHAVIOR*/
void		child_behavior(t_all *all);
void		child2_behavior(t_all *all);
int			parents_behavior(t_all *all);

    /*LST*/
void		path_in_lst(t_all *all);
void		get_path(t_all *all);
void		put_in_lst(t_all *all);

    /*PIPE_FORK*/
void		create_pipe(t_all *all);
void		create_fork(t_all *all);

    /*MAIN*/
void		pipex(t_all *all);
void		all_initialization(int argc, char **argv, char **envp, t_all *all);

#endif
