/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:00:09 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/01/11 15:50:29 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

#define HEX_BASE 16

char	*ft_itoc(int n)
{
	char	c;
	char	*res;

	c = n + 48;
	res = NULL;
	res = malloc(sizeof(unsigned char) * 1 + 1);
	if (res == NULL)
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

int	get_len_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

char	*ft_itohex(unsigned int nbr)
{
	int				len_hex;
	char			*char_hex;
	int				tmp;
	unsigned int	i;

	if (nbr == 0)
		return (ft_itoc(0));
	len_hex = get_len_hex(nbr);
	char_hex = malloc(sizeof(char) * len_hex);
	if (char_hex == NULL)
		return (NULL);
	i = len_hex - 2;
	while (nbr > 0)
	{
		tmp = nbr % HEX_BASE;
		if (tmp < 10)
			char_hex[i] = tmp + '0';
		else
			char_hex[i] = tmp - 10 + 'A';
		i--;
		nbr = nbr / HEX_BASE;
	}
	char_hex[len_hex - 1] = '\0';
	return (char_hex);
}

int	get_len_point(size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_size_to_hex(size_t nbr)
{
	int		len_hex;
	char	*char_hex;
	int		tmp;
	int		i;

	len_hex = get_len_point(nbr);
	char_hex = malloc(sizeof(char) * (len_hex + 3));
	if (char_hex == NULL)
		return (NULL);
	i = len_hex + 1;
	while (nbr > 0)
	{
		tmp = nbr % HEX_BASE;
		if (tmp < 10)
			char_hex[i] = tmp + '0';
		else
			char_hex[i] = tmp - 10 + 'A';
		i--;
		nbr = nbr / HEX_BASE;
	}
	char_hex[len_hex + 2] = '\0';
	char_hex[0] = '0';
	char_hex[1] = 'x';
	return (char_hex);
}
