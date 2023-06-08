/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:47:13 by ode-cleb          #+#    #+#             */
/*   Updated: 2022/11/07 12:41:05 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isalpha(' '));
	printf("%d\n", ft_isalpha('x'));
	printf("%d\n", ft_isalpha('O'));
	printf("%d\n", ft_isalpha('X'));
}
*/
