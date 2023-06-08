/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:17:58 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/09 12:08:27 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size1;
	size_t	size2;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	size2 = ft_strlen(src);
	size1 = ft_strlen(dest);
	j = size1;
	if (size == 0 || size <= size1)
		return (size2 + size);
	while (src[i] && size - size1 - 1 > i)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (size2 + size1);
}
