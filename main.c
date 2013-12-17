/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:00:08 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/17 17:23:54 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_draw(void *mlx, void *win)
{
	t_point		grid;
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
		grid.y = -1;
		while (++grid.y <= 720)
			mlx_pixel_put(mlx, win, grid.x, grid.y, 0x00FF00);
		grid.x = grid.x + 50;
	}
	ft_trace(point1, point2, mlx, win);
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

int		expose_hook(t_env *e)
{
	ft_draw(e->mlx, e->win);
	return (0);
}

int		main()
{
	t_env	new;

	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 720, 720, "42");
	mlx_key_hook(new.win, key_hook, &new);
	mlx_expose_hook(new.win, expose_hook, &new);
	mlx_mouse_hook(new.win, mouse_hook, &new);
	ft_draw(new.mlx, new.win);
	mlx_loop(new.mlx);
	return (0);
}
