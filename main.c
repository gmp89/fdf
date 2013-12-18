/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:00:08 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/18 15:38:39 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float sqrt1(const float x);
#include <stdio.h>
#include "header.h"

void		ft_draw(void *mlx, void *win, int **tab)
{
/*	t_point		grid;
	t_point		point1;
	t_point		point2;

	point1.x = 100;
	point1.y = 100;
	point2.x = 320;
	point2.y = 520;
	grid.y = 0;
	while (grid.y <= 720)
	{
		grid.x = -1;
		while (++grid.x <= 720)
			mlx_pixel_put(mlx, win, grid.x, grid.y, 0x00FF00);
		grid.y = grid.y + 50;
	}
	grid.x = 0;
	while (grid.x <= 720)
	{
		while (++grid.y <= 720)
			mlx_pixel_put(mlx, win, grid.x, grid.y, 0x00FF00);
		grid.x = grid.x + 50;
	}*/
	ft_draw_all(tab, mlx, win);
}

void	ft_trace(t_point point1, t_point point2, void *mlx, void *win)
{
	t_delta		delta;

	delta.dx = point2.x - point1.x;
	delta.dy = point2.y - point1.y;
	delta.dp = 2 * delta.dy - delta.dx; /* Valeur initiale de dp */
	delta.deltaE = 2 * delta.dy;
	delta.deltaNE = 2 * (delta.dy - delta.dx);
	delta.x = point1.x;
	delta.y = point1.y;
	mlx_pixel_put(mlx, win, delta.x, delta.y, 0xFF00FF);
	while (delta.x < point2.x)
	{
		if (delta.dp <= 0) /* On choisit le point E */
		{
			delta.dp = delta.dp + delta.deltaE;	/* Nouveau dp */
			delta.x++;				/* Calcul de x_p+1 */							/* y_p+1 = y_p */
		}
		else /* On choisit le point NE */
		{
			delta.dp = delta.dp + delta.deltaNE; /* Nouveau dp */
			delta.x++; /* Calcul de x_p+1 */
			delta.y++; /* Calcul de y_p+1 */
		}
		mlx_pixel_put(mlx, win, delta.x, delta.y, 0xFF00FF);
	}
}



int		key_hook(int keycode, t_env *e)
{
	ft_putstr("key : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	ft_putstr("mouse: ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putchar(':');
	ft_putnbr(y);
	ft_putchar(')');
	ft_putchar('\n');
	return (0);
}

int		expose_hook(t_env *e, int **tab)
{
	ft_draw(e->mlx, e->win, tab);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	new;
	int		**tab;

	tab = ft_get_data(argc, argv);
	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 720, 720, "42");
	mlx_key_hook(new.win, key_hook, &new);
	mlx_expose_hook(new.win, expose_hook, &new);
	mlx_mouse_hook(new.win, mouse_hook, &new);
	ft_draw(new.mlx, new.win, tab);
	mlx_loop(new.mlx);
	return (0);
}

float sqrt1(const float x)
{
  union
  {
    int i;
    float x;
  } u;
  u.x = x;
  u.i = (1<<29) + (u.i >> 1) - (1<<22); 
  
  // Two Babylonian Steps (simplified from:)
  // u.x = 0.5f * (u.x + x/u.x);
  // u.x = 0.5f * (u.x + x/u.x);
  u.x =       u.x + x/u.x;
  u.x = 0.25f*u.x + x/u.x;

  return u.x;
}

void	ft_draw_all(int **tab, void *mlx, void *win)
{
	t_point	point1;
	t_point	point2;
	float	fi;
	float	fj;
	float	fz;
	int		i;
	int		j;

	i = 0;
	j = 1;
	point1.x = 100;
	point1.y = 10;
	while (tab[i] != (int *)NULL)
	{
		while (j < 10)
		{
			fi = i;
			fj = j;
			fz = tab[i][j];
			point2.x = ft_calc_ax(fi, fj, fz);
			ft_trace(point1, point2, mlx, win);
			point1 = point2;
			j++;
		}
		j = 1;
		i++;
	}
}
