/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:51:12 by gpetrov           #+#    #+#             */
/*   Updated: 2013/11/25 16:57:34 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;

	ret = 0;
	while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2 && n--)
	{
		++s1;
		++s2;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1 ;
	return (ret);
}
