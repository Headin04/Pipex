/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:37:04 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/16 14:59:55 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (size != '\0')
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		i++;
	}
	while (src[a] != '\0')
		a++;
	return (a);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	char	src[]= "Ave mes amis";
	char	dest[]= "Je sais pas du tout";

	printf("%ld\n", strlcpy(dest, src, 3));
	printf("%d\n", ft_strlcpy(dest, src, 3));
}
*/
