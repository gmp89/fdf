/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:30:23 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/18 15:16:15 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_calc_ay(float i, float j, float z)
{
	int		y;
	float	ay;
	float	d;
	float	e;

	i = i * GRID_SIZE;
	z = z * GRID_SIZE;
	j = j * GRID_SIZE;

	d = sqrt1((my_pow(i) + my_pow(i))) / 2;
	e = sqrt1((my_pow(j) + my_pow(j))) / 2;
	ay = d + e;
	return ((y = (int)ay)); 
}

int		ft_calc_ax(float i, float j, float z)
{
	int		x;
	float	ax;
	float	d;
	float	e;

	i = i * GRID_SIZE;
	z = z * GRID_SIZE;
	j = j * GRID_SIZE;

	d = sqrt1((my_pow(i) + my_pow(i))) / 2;
	e = sqrt1((my_pow(j) + my_pow(j))) / 2;
	ax = sqrt1(my_pow(i) - my_pow(d)) + sqrt1(my_pow(j) - my_pow(e));
	return ((x = (int)ax));
}

float my_pow(float x)
{
	return (x * x);
}


