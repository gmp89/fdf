/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:25:44 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/16 14:44:16 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != 0)
		i++;
	if (s[i] == 0 && s[i] != (char)c)
		return (NULL);
	else if (s[i] == (char)c)
		return ((char *)&s[i]);
	return ((char *)&s[i]);
}
