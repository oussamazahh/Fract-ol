/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:04:38 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 17:55:25 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

void	data_int(t_fractol *fractol)
{
	fractol->img.img_pixels = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
	fractol->iteration = 42;
	fractol->value_escap = 4;
	fractol->shift_x = 0;
	fractol->shift_y = 0;
	fractol->zoom = 1;
	fractol->target_zoom = fractol->zoom;
	fractol->target_shift_x = fractol->shift_x;
	fractol->target_shift_y = fractol->shift_y;
	fractol->tool_x = 4.0;
	fractol->tool_y = 4.0;
}

void	my_fractol_unit(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
	{
		error_msg();
		return ;
	}
	fractol->mlx_win = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT,
			fractol->name);
	if (!fractol->mlx_win)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		free(fractol->mlx_ptr);
		error_msg();
		return ;
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->mlx_win)
	{
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		free(fractol->mlx_ptr);
		error_msg();
		return ;
	}
	data_int(fractol);
}

int	grayscale_color(int i, int max_iter)
{
	int	color_intensity;

	color_intensity = (int)(255.0 * ((double)i / (double)max_iter));
	return ((color_intensity << 16) | (color_intensity << 8) | color_intensity);
}

void	rescale(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = (((x - 0.0) * (+2 - (-2)) / (WIDTH - 0)) + (-2)) * fractol->zoom
		+ fractol->shift_x;
	z.y = (((y - 0.0) * (+2 - (-2)) / (HEIGHT - 0)) + (-2)) * fractol->zoom
		+ fractol->shift_y;
	juila_int(fractol, &z, &c);
	while (i < fractol->iteration)
	{
		if (!ft_strcmp(fractol->name, "Burning_ship"))
			z = sum_complex(square_complex_burnin(z), c);
		else
			z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->value_escap)
		{
			fractol->color = grayscale_color(i, fractol->iteration);
			my_pixel_put(x, y, &fractol->img, fractol->color);
			return ;
		}
		i++;
	}
	my_pixel_put1(x, y, &fractol->img, WHITE);
}

void	my_intit_mlx(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			rescale(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_win,
		fractol->img.img_ptr, 0, 0);
}
