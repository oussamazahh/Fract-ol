/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:31:49 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 17:55:40 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

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
// int	grayscale_color(int i, int max_iter)
// {
// 	int	color_intensity;

// 	color_intensity = (int)(255.0 * ((double)i / (double)max_iter));
// 	return ((color_intensity << 16) | (color_intensity << 8) | color_intensity);
// }