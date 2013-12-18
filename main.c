/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:00:08 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/18 20:12:09 by wbeets           ###   ########.fr       */
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
int        ft_abs(int value)
{
    if (value < 0)
        return (-value);
    return (value);
}

void    ft_trace(t_point pt1, t_point pt2, void *mlx, void *win)
{
    t_delta        delta;

    delta.dx = ft_abs(pt2.x - pt1.x);
    delta.x = (pt1.x < pt2.x) ? 1 : -1;
    delta.dy = ft_abs(pt2.y - pt1.y);
    delta.y = (pt1.y < pt2.y) ? 1 : -1; 
    delta.deltaE = (delta.dx > delta.dy) ? delta.dx : -delta.dy;
    delta.deltaE = delta.deltaE / 2;
    while (1)
    {
        mlx_pixel_put(mlx, win, pt1.x, pt1.y, 0xFF00FF);
        if (pt1.x == pt2.x && pt1.y == pt2.y)
            break ;
        delta.deltaNE = delta.deltaE;
        if (delta.deltaNE > -delta.dx)
        {
            delta.deltaE -= delta.dy;
            pt1.x += delta.x;
        }
        if (delta.deltaNE < delta.dy)
        {
            delta.deltaE += delta.dx;
            pt1.y += delta.y;
        }
    }
}
//void	ft_trace(t_point point1, t_point point2, void *mlx, void *win)
//{
//int dx, sx;
//    int dy, sy;
//    int err, e2;
//    int x0 = point1.x;
//    int x1 = point2.x;
//    int y0 = point1.y;
//    int y1 = point2.y;
//
//    dx = abs(x1-x0);
//    sx = x0<x1 ? 1 : -1;
//    dy = abs(y1-y0);
//    sy = y0<y1 ? 1 : -1; 
//    err = (dx>dy ? dx : -dy)/2;
//    for(;;){
//        mlx_pixel_put(mlx, win, x0, y0, 0xFF00FF);
//        if (x0==x1 && y0==y1) break;
//        e2 = err;
//        if (e2 >-dx) { err -= dy; x0 += sx; }
//        if (e2 < dy) { err += dx; y0 += sy; }
//    }
//}
//


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
	point1.x = 300;
	point1.y = 20;
	while (tab[i] != '\0')
	{
		while (j <= tab[i][0])
		{
			fi = i;
			fj = j;
			fz = tab[i][j];
			point2.x = ft_calc_ax(fi, fj, fz);
			point2.y = ft_calc_ay(fi, fj, fz);
			ft_putstr(" 1x is ");
			ft_putnbr(point1.x);
			ft_putstr("\t 1y is ");
			ft_putnbr(point1.y);
			ft_putstr("\t 2x is ");
			ft_putnbr(point2.x);
			ft_putstr("\t 2y is ");
			ft_putnbr(point2.y);
			ft_putstr("\t j = ");
			ft_putnbr(j);
			ft_putstr("\t i = ");
			ft_putnbr(i);
			ft_putendl(" ");
			if (j != 1)
				ft_trace(point1, point2, mlx, win);
			usleep(10000);
			point1 = point2;
			j++;
		}
		j = 1;
		i++;
	}
	i = 0;
	j = 1;

	ft_putstr("2e boucle");
	while (j <= tab[i][0])
	{
		while (tab[i] != '\0')
		{
			fi = i;
			fj = j;
			fz = tab[i][j];
			point2.x = ft_calc_ax(fi, fj, fz);
			point2.y = ft_calc_ay(fi, fj, fz);
			ft_putstr(" 1x is ");
			ft_putnbr(point1.x);
			ft_putstr("\t 1y is ");
			ft_putnbr(point1.y);
			ft_putstr("\t 2x is ");
			ft_putnbr(point2.x);
			ft_putstr("\t 2y is ");
			ft_putnbr(point2.y);
			ft_putstr("\t j = ");
			ft_putnbr(j);
			ft_putstr("\t i = ");
			ft_putnbr(i);
			ft_putendl(" ");
			if (i != 0)
				ft_trace(point1, point2, mlx, win);
			usleep(10000);
			point1 = point2;
			i++;
		}
		i = 0;
		j++;
	}

}
