/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:17:04 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/24 16:16:11 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_nbr(unsigned int n, int fd)
{
	if (n > 0)
	{
		write_nbr(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_bis;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_bis = -n;
	}
	else
		n_bis = n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		write_nbr(n_bis, fd);
}
