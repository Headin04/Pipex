/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:18:44 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/01/11 16:01:44 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	lens1 = 0;
	lens2 = 0;
	if (s1 != NULL)
		lens1 = ft_strlen(s1);
	if (s2 != NULL)
		lens2 = ft_strlen(s2);
	s3 = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	else
	{
		if (s1 != NULL)
			ft_strlcpy(s3, s1, lens1 + 1);
		if (s2 != NULL)
			ft_strlcpy(s3 + lens1, s2, lens2 + 1);
	}
	return (s3);
}
