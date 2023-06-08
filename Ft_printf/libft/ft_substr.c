/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:17:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/09 12:10:53 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	final_size;
	char	*dest;
	size_t	slen;

	final_size = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start < slen)
	{
		if (slen - start >= len)
			final_size = len;
		else
			final_size = slen - start;
	}
	else
		start = slen;
	dest = (char *)malloc((final_size + 1) * sizeof(char));
	if (dest != NULL)
		ft_strlcpy(dest, s + start, final_size + 1);
	return (dest);
}
