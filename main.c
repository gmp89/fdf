/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 16:00:08 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/16 20:25:00 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_draw(void *mlx, void *win)
{
	int	x;
	int	y;

	y = 100;
	while (y <= 200)
	{
		x = 100;
		while (x <= 200)
		{
			usleep(100);
			mlx_pixel_put(mlx, win, x, y, 0xFF00FF);
			x++;
		}
		y++;
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
