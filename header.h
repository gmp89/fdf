/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:57:28 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/18 20:33:29 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define GRID_SIZE  20
# define OFFSET_X  200
# define OFFSET_Y  -10


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

typedef union		u_union
{
	int				i;
	float			x;
}					t_union;

typedef struct		s_struc
{
	float			fi;
	float			fj;
	float			fz;
	int				i;
	int				j;
}					t_struct_draw_all;

int		ft_calc_ay(float i, float j, float z);
float	sqrt1(const float x);
int		ft_calc_ax(float i, float j, float z);
float	my_pow(float x);
void	ft_draw(void *mlx, void *win, int **tab);
void	ft_draw_all(int **tab, void *mlx, void *win);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		expose_hook(t_env *e, int **tab);
int		**ft_get_data(int argc, char **argv);
int		ft_tablen(char **tab);
int		ft_data_size(char *file);
int		*ft_put_data(char *str);
void	ft_trace(t_point point1, t_point point2, void *mlx, void *win);

#endif /* HEADER_H */
