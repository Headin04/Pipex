/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:03:10 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/09 12:13:01 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char	*s3;
	size_t	lens1;
	size_t	lens2;

	lens1 = 0;
	lens2 = 0;
	if (s1 != NULL)
		lens1 = ft_strlen(s1);
	if (s2 != NULL)
		lens2 = size;
	s3 = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	else
	{
		if (s1 != NULL)
			ft_strlcpy(s3, s1, lens1 + 1);
		if (s2 != NULL)
			ft_strlcpy((s3 + lens1), s2, (lens2 + 1));
	}
	if (s1 != NULL)
		free (s1);
	return (s3);
}
