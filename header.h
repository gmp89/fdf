/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:57:28 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/16 20:14:24 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

void	ft_draw(void *mlx, void *win);

#endif /* HEADER_H */
