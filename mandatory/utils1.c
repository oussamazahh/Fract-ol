/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:21:10 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 18:38:40 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

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

int	grayscale_color(int i, int max_iter)
{
	int	color_intensity;

	color_intensity = (int)(255.0 * ((double)i / (double)max_iter));
	return ((color_intensity << 16) | (color_intensity << 8) | color_intensity);
}

void	data_int(t_fractol *fractol)
{
	fractol->img.img_pixels = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
	fractol->iteration = 42;
	fractol->value_escap = 4;
	fractol->shift_x = 0;
	fractol->shift_y = 0;
	fractol->zoom = 1;
	fractol->target_shift_x = fractol->shift_x;
	fractol->target_shift_y = fractol->shift_y;
	fractol->target_zoom = fractol->zoom;
}
