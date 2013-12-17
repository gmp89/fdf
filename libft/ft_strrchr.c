/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:21:07 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/16 14:52:44 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char		c2;

	i = ft_strlen((char *)s) + 1;
	c2 = (char) c;
	while (i > 0 && s[i] != c2)
		i--;
	if (s[i] == c2)
		return ((char *)&s[i]);
	return (NULL);
}
