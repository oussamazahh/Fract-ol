/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:19:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 18:25:53 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	update(t_fractol *fractol)
{
	fractol->shift_x += (fractol->target_shift_x - fractol->shift_x);
	fractol->shift_y += (fractol->target_shift_y - fractol->shift_y);
	fractol->zoom += (fractol->target_zoom - fractol->zoom);
}

int	mouse_event(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
		fractol->target_zoom *= 0.95;
	else if (button == 5)
		fractol->target_zoom *= 1.05;
	return (0);
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == ECHAP)
	{
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		free(fractol->mlx_ptr);
		exit(1);
	}
	if (key == RIGHT)
		fractol->target_shift_x -= (0.5 * fractol->zoom);
	if (key == LEFT)
		fractol->target_shift_x += (0.5 * fractol->zoom);
	if (key == UP)
		fractol->target_shift_y -= (0.5 * fractol->zoom);
	if (key == DOWN)
		fractol->target_shift_y += (0.5 * fractol->zoom);
	if (key == PLUS || key == MIN)
	{
		if (key == PLUS)
			fractol->iteration += 5;
		else if (key == MIN)
			fractol->iteration -= 5;
		my_intit_mlx(fractol);
	}
	return (0);
}
