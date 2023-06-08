/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:07:23 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/03/14 18:52:04 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_nb_word(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] != '\0' && s[j] == c)
		j++;
	while (s[j] != '\0')
	{
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == '\0'))
			i++;
		j++;
	}
	return (i);
}

size_t	get_len(char const *s, char c)
{
	size_t	len_word;

	len_word = 0;
	while (s[len_word] != c && s[len_word] != '\0')
		len_word++;
	return (len_word);
}

char	*get_word(char const **s, char c)
{
	char	*dest;
	size_t	len_word;

	while (**s == c)
		++(*s);
	len_word = get_len(*s, c);
	dest = (char *)malloc((len_word + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	else
		ft_strlcpy(dest, *s, len_word + 1);
	*s += len_word;
	return (dest);
}

static void	free_all(char **split, size_t nb_word)
{
	while (split[nb_word - 1] != NULL)
	{
		free(split[nb_word - 1]);
		nb_word--;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	nb_word;
	size_t	i;

	if (s == NULL)
		return (NULL);
	nb_word = get_nb_word(s, c);
	i = 0;
	split = (char **)malloc((nb_word + 1) * sizeof(char *));
	if (split != NULL)
	{
		split[nb_word] = NULL;
		while (i < nb_word)
		{
			split[i] = get_word(&s, c);
			if (split[i] == NULL)
			{
				free_all(split, nb_word);
				i = -1;
			}
			i++;
		}
	}
	return (split);
}
