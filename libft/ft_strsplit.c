/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:31:22 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/16 14:30:29 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbstr_count(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			i++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (i);
}

static size_t	ft_strlenc(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	*p;
	char	**strtab;
	char	**pstrtab;

	i = 0;
	p = (char *)s;
	strtab = (char **)malloc(sizeof(char *) * (ft_nbstr_count(p, c) + 1));
	if (strtab == NULL)
		return (NULL);
	pstrtab = strtab;
	while (i < ft_nbstr_count((char *)s, c))
	{
		while (*p == c)
			p++;
		*pstrtab = ft_strnew(ft_strlenc(p, c) + 1);
		ft_memcpy(*pstrtab, p, ft_strlenc(p, c));
		while (*p != c)
			p++;
		pstrtab++;
		i++;
	}
	*pstrtab = NULL;
	return (strtab);
}
