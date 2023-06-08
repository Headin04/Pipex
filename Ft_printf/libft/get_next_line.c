/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:42:53 by ode-cleb          #+#    #+#             */
/*   Updated: 2023/02/03 14:38:02 by ode-cleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	does_rest_contain_line(char *rest, char **final)
{
	size_t	i;

	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	*final = ft_strnjoin(*final, rest, i + 1);
	if (i != ft_strlen(rest))
	{
		ft_strlcpy(rest, rest + i + 1, (ft_strlen(rest) - i));
		return (true);
	}
	else
		bzero(rest, ft_strlen(rest));
	return (false);
}

bool	does_buf_contain_line(char *buf, char **final, char *rest)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (i == 0 && buf[0] != '\n')
		return (NULL);
	*final = ft_strnjoin(*final, buf, i + 1);
	if (i < BUFFER_SIZE || buf[0] == '\n')
	{
		ft_strlcpy(rest, buf + i + 1, (ft_strlen(buf) - i + 2));
		free(buf);
		return (true);
	}
	else
	{
		ft_strlcpy(rest, buf, (ft_strlen(buf) - i));
		bzero(buf, ft_strlen(buf));
		return (false);
	}
}

char	*get_next_line2(int fd, char *buf, char *final, char *rest)
{
	ssize_t	rbyte;

	rbyte = -1;
	rbyte = read(fd, buf, BUFFER_SIZE);
	if (rbyte == -1)
	{
		free(buf);
		return (NULL);
	}
	while (rbyte > 0)
	{
		if (rbyte == 1 && buf[0] == '\n' && final == NULL)
		{
			final = ft_strnjoin(final, buf, ft_strlen(buf));
			free(buf);
			return (final);
		}
		else if (does_buf_contain_line(buf, &final, rest) == true && rbyte != 0)
			return (final);
		else
			rbyte = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (final);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*final;
	static char	rest[BUFFER_SIZE + 1] = {0};

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	final = NULL;
	buf = NULL;
	if (rest[0] != '\0')
	{
		if (does_rest_contain_line(rest, &final) == true)
			return (final);
	}
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (buf == NULL)
		return (NULL);
	final = get_next_line2(fd, buf, final, rest);
	return (final);
}
