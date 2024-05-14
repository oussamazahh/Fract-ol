/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:19:38 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 16:00:37 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static void	help_echap(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
	exit (0);
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == ECHAP)
		help_echap(fractol);
	if (key == RIGHT)
		return (fractol->shift_x -= (0.5 * fractol->zoom)
			, clear_draw(fractol), 1);
	if (key == LEFT)
		return (fractol->shift_x += (0.5 * fractol->zoom)
			, clear_draw(fractol), 1);
	if (key == UP)
		return (fractol->shift_y -= (0.5 * fractol->zoom)
			, clear_draw(fractol), 1);
	if (key == DOWN)
		return (fractol->shift_y += (0.5 * fractol->zoom)
			, clear_draw(fractol), 1);
	if (key == PLUS || key == MIN)
	{
		if (key == PLUS)
			fractol->iteration += 20;
		else if (key == MIN)
			fractol->iteration -= 20;
		clear_draw(fractol);
		return (1);
	}
	return (0);
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
	exit(0);
}
