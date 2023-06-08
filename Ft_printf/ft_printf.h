/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:36:35 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/16 15:59:21 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <bsd/string.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <stdarg.h>

typedef struct s_conv
{
	int	minus;
	int	zero;
	int	hashtag;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	index;
}	t_conv;

void	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
int		ft_printf(const char *str, ...);
int		ft_vdprintf(int fd, const char *str, va_list args);
size_t	ft_print(t_list *lst, int fd);
t_list	*ft_lst(const char *str);
void	ft_nn_percent(const char **str, t_list **lst);
void	ft_nn_text(const char **str, t_list **lst);
void	ft_lst_lstdelone2(t_list **lst);
void	ft_scan_list(t_list **lst, va_list args);
void	ft_scan_node(t_list **lst, va_list args);
void	ft_check_flags(t_list **lst, t_conv **flags);
void	ft_check_convert(t_list **lst, va_list args);
t_conv	*ft_initial_flags(t_conv *flags);
void	ft_flags(char *str, t_conv **flags);
void	ft_width(char *str, t_conv **flags);
void	ft_precision(char *str, t_conv **flags);
char	*ft_size_to_hex(size_t nbr);
char	*ft_itohex(unsigned int nbr);
char	*ft_itoctoa(int n, t_list **lst);
char	*ft_uitoa(unsigned int n);
char	*ft_if_null(t_list **lst, char *str);
char	*ft_if_nil(size_t nbr);
int		ft_dprintf(const char *str, ...);
int		ft_vdprintf(int fd, const char *str, va_list args);

#endif
