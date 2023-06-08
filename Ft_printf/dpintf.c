/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpintf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:04:16 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/16 16:04:21 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *str, va_list args)
{
	size_t	i;
	t_list	*lst;

	i = 0;
	lst = NULL;
	if (str == NULL)
		return (-1);
	lst = ft_lst(str);
	ft_scan_list(&lst, args);
	i = ft_print(lst, fd);
	return (i);
}

int	ft_dprintf(const char *str, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	va_start(args, str);
	ft_vdprintf(2, str, args);
	va_end(args);
	return (i);
}
