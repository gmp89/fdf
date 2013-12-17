/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:57:28 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/17 17:54:10 by wbeets           ###   ########.fr       */
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

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_delta
{
	int				dx;
	int				dy;
	int				dp;
	int				deltaE;
	int				deltaNE;
	int				x;
	int				y;
}					t_delta;

void	ft_draw(void *mlx, void *win);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		expose_hook(t_env *e);
int		**ft_get_data(int argc, char **argv);
int		ft_tablen(char **tab);
int		ft_data_size(char *file);
int		*ft_put_data(char *str);
void	ft_trace(t_point point1, t_point point2, void *mlx, void *win);

#endif /* HEADER_H */
