/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:41 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/12/02 16:29:04 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t m, size_t n)
{
	const size_t	mn = m * n;
	void			*dest;

	dest = NULL;
	if (mn == 0 || m <= SIZE_MAX / n)
		dest = malloc(mn);
	if (dest != NULL)
		ft_bzero(dest, mn);
	return (dest);
}
