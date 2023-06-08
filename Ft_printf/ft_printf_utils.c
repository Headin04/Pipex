/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:21:55 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/09 11:48:49 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#define HEX_BASE 16

static long int	get_len(long int n)
{
	long int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= (-1);
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoctoa(int n, t_list **lst)
{
	char	c;
	char	*res;

	c = n;
	if (n == 0)
		(*lst)->nullc = 1;
	res = NULL;
	res = malloc(sizeof(unsigned char) * 1 + 1);
	if (res == NULL)
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	char			*dest;

	len = get_len(n);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	len--;
	if (n == 0)
		dest[0] = '0';
	while (n > 0)
	{
		dest[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (dest);
}
