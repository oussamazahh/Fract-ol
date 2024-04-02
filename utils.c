/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:35:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/02 23:08:19 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
void	error(void)
{
	perror("Error in malloc");
	exit(EXIT_FAILURE);
}

void	my_intit_mlx(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		error();
	fractol->mlx_win = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT,
			fractol->name);
	if (!fractol->mlx_win)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		free(fractol->mlx_ptr);
		error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
		error();
	}
	fractol->img.img_pixels = mlx_get_data_addr(fractol->img.img_ptr,
												&fractol->img.bpp,
												&fractol->img.size_line,
												&fractol->img.endian);
	fractol->value_escap = 4;
	fractol->iteration = 42;
	fractol->zoom = 1.0;
	fractol->shift_x = 0;
	fractol->shift_y = 0;
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_pixels + offset) = color;
}

double	edit_resc(double value, double old_value_min, double old_value_max,
		double new_value_min, double new_value_max)
{
	return (((value - old_value_min) * (new_value_max - new_value_min)
			/ (old_value_max - old_value_min)) + new_value_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	tmp;

	tmp.x = z1.x + z2.x;
	tmp.y = z1.y + z2.y;
	return (tmp);
}

t_complex	square_complex(t_complex z)
{
	t_complex	tmp;

	tmp.x = (z.x * z.x) - (z.y * z.y);
	tmp.y = (z.y * z.x * 2);
	return (tmp);
}
static void	rescale(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (edit_resc(x, 0, WIDTH, -2, +2) * fractol->zoom + fractol->shift_x);  //rescale in x
	c.y = (edit_resc(y, 0, HEIGHT, -2, +2) * fractol->zoom + fractol->shift_y); //rescale in y
	while (i < fractol->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->value_escap) //c = √a^2 + b^2
		{
			fractol->color = edit_resc(i, 0, fractol->iteration, BLACK, TKHERBIQA);
			my_pixel_put(x, y, &fractol->img, fractol->color);
			return ;
		}
		i++;
	}
	fractol->color = DARK_BLUE;
	my_pixel_put(x, y, &fractol->img, fractol->color);
}

void	my_fractol_unit(t_fractol *fractol)
{
	int x;
	int y;

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

int mouse_event(int button, int x, int y, t_fractol *fractol) {
    if (button == 4)
	{ // Scroll up
        fractol->zoom *= 0.95; // Increase zoom level
		printf("%.2f",fractol->zoom);
    }
	else if (button == 5)
	{ // Scroll down
        fractol->zoom *= 1.05; 
    }
	my_fractol_unit(fractol);
	return (0);
}

void	my_mouse_hook(t_fractol *fractol)
{
	
	mlx_mouse_hook(fractol->mlx_win, mouse_event, fractol);
}
int	key_hook(int key, t_fractol *fractol)
{
	if (key == KEY_ECHAP)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
		mlx_destroy_image(fractol->mlx_ptr, fractol->img.img_ptr);
		free(fractol->mlx_ptr);
		exit(1);
	}
	if(key == XK_KP_Up)
		fractol->shift_y -= (0.5 + fractol->zoom);
	if (key == XK_KP_PLUS) //plus
		fractol->iteration += 10;
	if (key == XK_KP_MIN) //minus
		fractol->iteration -= 10;
	if (key == XK_KP_Left) //left
		fractol->shift_x += (0.5 + fractol->zoom);
	if (key == XK_KP_Right) //right
		fractol->shift_x -= (0.5 + fractol->zoom);
	if (key == XK_KP_Down) //down
		fractol->shift_y += (0.5 + fractol->zoom);
	// printf("%d", key);
	// rend
	my_fractol_unit(fractol);
	return (0);
}
int color_change(int key, t_fractol *fractol)
{
	if (key == DARK_BLUE)
	{
		fractol->color = MAGENTA;
		my_fractol_unit(fractol);
	}
	else
	{
		fractol->color = DARK_BLUE;
	}
	// sleep(2);
	return (0);
}