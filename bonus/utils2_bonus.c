/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:50:44 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 17:52:00 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

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

void	data_int_j(t_fractol *fractol, double x, double y)
{
	fractol->julia_x = x;
	fractol->julia_y = y;
}

void	error_msg(void)
{
	write(2, "error in malloc", 15);
	exit(1);
}
