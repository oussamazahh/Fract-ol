/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:39:55 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 18:12:41 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

void	exit_echap(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
	exit(0);
}

void	help_x_y(int key, t_fractol *fractol, double shiffting_x
	, double shiffting_y)
{
	if (key == RIGHT)
	{
		fractol->x_pos_min -= (shiffting_x);
		fractol->x_pos_max -= (shiffting_x);
		clear_draw(fractol);
	}
	if (key == LEFT)
	{
		fractol->x_pos_min += (shiffting_x);
		fractol->x_pos_max += (shiffting_x);
		clear_draw(fractol);
	}
	if (key == UP)
	{
		fractol->y_pos_min -= (shiffting_y);
		fractol->y_pos_max -= (shiffting_y);
		clear_draw(fractol);
	}
	if (key == DOWN)
	{
		fractol->y_pos_min += (shiffting_y);
		fractol->y_pos_max += (shiffting_y);
		clear_draw(fractol);
	}
}

int	key_hook(int key, t_fractol *fractol)
{
	double	shiffting_x;
	double	shiffting_y;

	shiffting_x = (fractol->x_pos_max - fractol->x_pos_min) / 10;
	shiffting_y = (fractol->y_pos_max - fractol->y_pos_min) / 10;
	if (key == ECHAP)
		exit_echap(fractol);
	help_x_y(key, fractol, shiffting_x, shiffting_y);
	if (key == PLUS || key == MIN)
	{
		if (key == PLUS)
			fractol->iteration += 20;
		else if (key == MIN)
			fractol->iteration -= 20;
		clear_draw(fractol);
	}
	else
		return (0);
	return (0);
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
	exit(0);
}
