/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 15:04:29 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/18 19:56:04 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		**ft_get_data(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		**tab;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [data_file]");
		return (0);
	}
	i = ft_data_size(argv[1]);
	tab = (int**)malloc((i + 1)* (sizeof(*tab)));
	tab[i + 1] = '\0';
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_put_data(line);
		i++;
		free(line);
	}
	return (tab);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		ft_data_size(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int		*ft_put_data(char *str)
{
	char	**chartab;
	int		*tab;
	int		i;
	int		j;

	chartab = ft_strsplit(str, ' ');
	i = ft_tablen(chartab);
	tab = (int*)malloc(i * (sizeof(*tab)));
	tab[0] = i;
	j = 0;
	while (++j <= i)
		tab[j] = ft_atoi(chartab[j - 1]);
	return (tab);
}
