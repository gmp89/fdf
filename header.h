/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:57:28 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/17 17:15:45 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

void	ft_draw(void *mlx, void *win);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		expose_hook(t_env *e);
int		**ft_get_data(int argc, char **argv);
int		ft_tablen(char **tab);
int		ft_data_size(char *file);
int		*ft_put_data(char *str);


#endif /* HEADER_H */
