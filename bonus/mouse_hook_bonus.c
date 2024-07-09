/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:22:52 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/19 21:41:32 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

int	pos_cursor(int x, int y, t_fractol *fractol)
{
	fractol->center_x = x;
	fractol->center_y = y;
	return (0);
}

void	correct_zoom(t_fractol *fractol, double size, int button)
{
	double	x;
	double	y;

	x = ((fractol->center_x) * (fractol->x_pos_max - fractol->x_pos_min)
			/ (fractol->width)) + fractol->x_pos_min;
	y = ((fractol->center_y) * (fractol->y_pos_max - fractol->y_pos_min)
			/ (fractol->height)) + fractol->y_pos_min;
	if (button == 4)
	{
		fractol->x_pos_min += (x - fractol->x_pos_min) * size;
		fractol->x_pos_max -= (fractol->x_pos_max - x) * size;
		fractol->y_pos_min += (y - fractol->y_pos_min) * size;
		fractol->y_pos_max -= (fractol->y_pos_max - y) * size;
	}
	else if (button == 5)
	{
		fractol->x_pos_min -= (x - fractol->x_pos_min) * size;
		fractol->x_pos_max += (fractol->x_pos_max - x) * size;
		fractol->y_pos_min -= (y - fractol->y_pos_min) * size;
		fractol->y_pos_max += (fractol->y_pos_max - y) * size;
	}
}

int	mouse_event(int button, int x, int y, t_fractol *fractol)
{
	double	size;

	(void)x;
	(void)y;
	if (button == 4)
	{
		size = 0.1;
		fractol->zoom *= size;
		correct_zoom(fractol, size, button);
		mlx_clear_window(fractol->mlx_ptr, fractol->mlx_win);
		my_intit_mlx(fractol);
	}
	else if (button == 5)
	{
		size = 0.1;
		fractol->zoom /= size;
		correct_zoom(fractol, size, button);
		mlx_clear_window(fractol->mlx_ptr, fractol->mlx_win);
		my_intit_mlx(fractol);
	}
	else
		return (0);
	return (0);
}
