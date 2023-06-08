/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:15:21 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/01/11 16:05:29 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	ft_handler_convert(t_list **lst, char *str, va_list args)
{
	if (*str == '%')
		(*lst)->ncontent = ft_itoctoa('%', lst);
	if (*str == 'c')
		(*lst)->ncontent = ft_itoctoa(va_arg(args, int), lst);
	else if (*str == 's')
		(*lst)->ncontent = ft_if_null(lst, va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		(*lst)->ncontent = ft_itoa(va_arg(args, int));
	else if (*str == 'u')
		(*lst)->ncontent = ft_uitoa(va_arg(args, unsigned int));
	else if (*str == 'x')
		(*lst)->ncontent = ft_tolower(ft_itohex(va_arg(args, unsigned int)));
	else if (*str == 'X')
		(*lst)->ncontent = ft_toupper(ft_itohex(va_arg(args, unsigned int)));
	else if (*str == 'p')
		(*lst)->ncontent = ft_tolower(ft_if_nil(va_arg(args, size_t)));
}

void	ft_check_convert(t_list **lst, va_list args)
{
	int		len;
	char	*chr;

	len = ft_strlen((*lst)->content);
	chr = ft_strchr("cspiduxX%", ((*lst)->content)[len - 1]);
	if (chr != NULL)
		ft_handler_convert(lst, chr, args);
}

void	ft_scan_list(t_list **lst, va_list args)
{
	t_list	*tmp;

	tmp = *lst;
	while (*lst != NULL)
	{
		if (((*lst)->content)[0] == '%')
			ft_check_convert(lst, args);
		*lst = (*lst)->next;
	}
	*lst = tmp;
}
