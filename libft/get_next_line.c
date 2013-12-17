/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:46:54 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/16 15:11:47 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int const fd, char **line)
{
	static char		*buf;
	long			ret;
	int				i;

	i = 0;
	while ((buf && buf[i] != 0)
		|| ((!buf || !buf[i])
			&& (buf = ft_make_buf(fd, (char *)buf, &ret))))
	{
		if (buf[i] == '\n' || (!buf[i] && ret <= BUFF_SIZE))
		{
			if (ret == -1)
				return (-1);
			*line = ft_strnew(ft_strlen(buf + 1));
			*line = ft_strncpy(*line, buf, i);
			ft_memmove(buf, buf + i + 1, ft_strlen(buf) - i + 1);
			if (ret == 0)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_make_buf(int const fd, char *buf, long *ret)
{
	char		*str;

	str = ft_strnew(BUFF_SIZE + 1);
	if ((*ret = read(fd, str, BUFF_SIZE)))
	{
		if (buf == NULL)
		{
			buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
			buf = ft_strdup(str);
		}
		else if (buf != NULL)
			buf = ft_strjoin(buf, str);
	}
	return (buf);
}
