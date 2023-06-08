/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:26:11 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/09 12:10:03 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start(char *s1, char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	return (i);
}

size_t	ft_end(char *s1, char *set, int start, size_t i)
{
	while (s1[i] != s1[start])
	{
		if (ft_strchr(set, s1[i]))
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	char	*s2;
	size_t	start;
	size_t	end;

	if (s1 != NULL)
	{
		start = ft_start(s1, set);
		i = ft_strlen(s1);
		end = ft_end(s1, set, start, i);
		s2 = ft_substr(s1, start, end - start + 1);
		return (s2);
	}
	return (NULL);
}
