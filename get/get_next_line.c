/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:26:12 by yhadari           #+#    #+#             */
/*   Updated: 2019/11/10 10:40:54 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c != *((unsigned char*)s + i))
			i++;
		else
			return ((unsigned char*)s + i);
	}
	return (NULL);
}

size_t				ft_strbn(char *s)
{
	size_t i;

	i = 0;
	while (i < BUFFER_SIZE && s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int					get_next_line(int fd, char **line)
{
	static	char	*p;
	char			*buf;
	int				k;

	buf = malloc((BUFFER_SIZE + 1)*(sizeof(char)));
	*line = ft_strdup("");
	while (p)
	{
		if (ft_memchr(p, '\n', ft_strlen(p)))
		{
			*line = ft_substr(p, 0, ft_strbn(p));
			p = ft_strdup(ft_memchr(p, '\n', ft_strlen(p)) + 1);
			return (1);
		}
		*line = ft_strdup(p);
		p = NULL;
	}
	while ((k = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[k] = '\0';
		if ((p = ft_memchr(buf, '\n', ft_strlen(buf))))
		{
			p = ft_strdup(p+1);
			*line = ft_strjoin(*line, ft_substr(buf, 0, ft_strbn(buf)));
			return (1);
		}
		*line = ft_strjoin(*line, buf);
	}
	if (**line == 0)
		return (k);
	return (1);
}
