/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:04:38 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 18:39:26 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

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

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	p;
	int	alpha;
	int	transparency;

	p = (y * img->size_line) + (x * 4);
	alpha = (color >> 24) & 0xFF;
	if (x < 5)
		transparency = (5 - x) * alpha / 5;
	else
		transparency = alpha;
	img->img_pixels[p + 0] = (color >> 8) & 0xFF;
	img->img_pixels[p + 1] = (color >> 8) & 0xFF;
	img->img_pixels[p + 2] = transparency;
	img->img_pixels[p + 3] = transparency;
}

void	my_pixel_put1(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_pixels + offset) = color;
}

void	rescale(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	i = 0;
	z.x = (((x - 0.0) * (+2 - (-2)) / (WIDTH - 0)) + (-2)) * fractol->zoom
		+ fractol->shift_x;
	z.y = (((y - 0.0) * (+2 - (-2)) / (HEIGHT - 0)) + (-2)) * fractol->zoom
		+ fractol->shift_y;
	juila_int(fractol, &z, &c);
	while (i < fractol->iteration)
	{
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
