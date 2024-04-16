/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:39:55 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 17:59:41 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

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

void	update_fractal(t_fractol *fractol)
{
	fractol->zoom += (fractol->target_zoom - fractol->zoom);
	fractol->shift_x += (fractol->target_shift_x - fractol->shift_x);
	fractol->shift_y += (fractol->target_shift_y - fractol->shift_y);
}

void	zoom(int x, int y, int part, t_fractol *fractol)
{
	if (part == 0)
	{
		fractol->target_shift_x -= (0.1 * fractol->zoom);
		fractol->target_shift_y -= (0.1 * fractol->zoom);
	}
	else if (part == 1)
	{
		fractol->target_shift_y -= (0.1 * fractol->zoom);
		fractol->target_shift_x += (0.1 * fractol->zoom);
	}
	else if (part == 2)
	{
		fractol->target_shift_y += (0.1 * fractol->zoom);
		fractol->target_shift_x -= (0.1 * fractol->zoom);
	}
	else
	{
		fractol->target_shift_y += (0.1 * fractol->zoom);
		fractol->target_shift_x += (0.1 * fractol->zoom);
	}
}

int	mouse_event(int button, int x, int y, t_fractol *fractol)
{
	int	part;

	if (button == 4)
		fractol->target_zoom *= 1.1;
	if (button == 5)
		fractol->target_zoom /= 1.1;
	if (x > WIDTH / 2)
		part = 1;
	if (x < WIDTH / 2)
		part = 0;
	if (y > HEIGHT / 2)
		part = part + 2 * 1;
	if (y < HEIGHT / 2)
		part *= part + 2 * 0;
	zoom(x, y, part, fractol);
	return (0);
}
