/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_sciling_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:04:38 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 18:08:32 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

void	check_burning(t_fractol *fractol, t_complex *z, t_complex *c)
{
	if (!ft_strcmp(fractol->name, "Burning_ship"))
		*z = sum_complex(square_complex_burnin(*z), *c);
	else
		*z = sum_complex(square_complex(*z), *c);
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
	fractol->center_x = 0.0;
	fractol->center_y = 0.0;
	fractol->width = WIDTH;
	fractol->height = HEIGHT;
	fractol->x_pos_min = -2.0;
	fractol->x_pos_max = +2.0;
	fractol->y_pos_min = -2.0;
	fractol->y_pos_max = +2.0;
}

void	my_fractol_unit(t_fractol *fractol, char *str)
{
	fractol->name = str;
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
		error_msg();
		return ;
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->mlx_win)
	{
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		error_msg();
	}
	data_int(fractol);
}

void	rescale(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = ((((x - 0.0) * (fractol->x_pos_max - (fractol->x_pos_min))
					/ (fractol->width - 0)) + (fractol->x_pos_min))
			+ fractol->shift_x);
	z.y = ((((y - 0.0) * (fractol->y_pos_max - (fractol->y_pos_min))
					/ (fractol->height - 0)) + (fractol->y_pos_min))
			+ fractol->shift_y);
	juila_int(fractol, &z, &c);
	while (i < fractol->iteration)
	{
		check_burning(fractol, &z, &c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->value_escap)
		{
			fractol->color = grayscale_color(i, fractol->iteration);
			my_pixel_put(x, y, &fractol->img, fractol->color);
			return ;
		}
		i++;
	}
	my_pixel_put_v1(x, y, &fractol->img, WHITE);
}

void	my_intit_mlx(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractol->height)
	{
		x = 0;
		while (x < fractol->width)
		{
			rescale(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->mlx_win,
		fractol->img.img_ptr, 0, 0);
}
