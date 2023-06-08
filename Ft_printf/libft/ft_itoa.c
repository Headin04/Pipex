/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:02:54 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/24 16:11:17 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	long	len;
	char	*dest;
	long	n_bis;

	n_bis = n;
	len = get_len(n_bis);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	len--;
	if (n_bis == 0)
		dest[0] = 48;
	if (n_bis < 0)
	{
		dest[0] = '-';
		n_bis *= (-1);
	}
	while (n_bis > 0)
	{
		dest[len] = n_bis % 10 + 48;
		n_bis /= 10;
		len--;
	}
	return (dest);
}
