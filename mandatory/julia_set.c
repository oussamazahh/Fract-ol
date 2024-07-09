/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:00:34 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/15 14:22:51 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	data_int_j(t_fractol *fractol, double x, double y)
{
	fractol->julia_x = x;
	fractol->julia_y = y;
}

void	juila_int(t_fractol *fractol, t_complex *z, t_complex *c)
{
	if (!ft_strcmp(fractol->name, "Julia"))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
		z->x = 0.0;
		z->y = 0.0;
	}
}
