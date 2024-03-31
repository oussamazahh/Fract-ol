/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:35:07 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/31 23:24:39 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

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
void    error()
{
    perror("Error in malloc");
    exit (EXIT_FAILURE);
}

void    my_intit_mlx(t_fractol *fractol)
{
    fractol->mlx_ptr = mlx_init();
    // if (!fractol->mlx_ptr)
    //     error();
    fractol->mlx_win = mlx_new_window(fractol->mlx_ptr, WIDTH, HEIGHT, fractol->name);
    // if (!fractol->mlx_win)
    // {
    //     mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
    //     // free(fractol->mlx_ptr);
    //     error();
    // }
    fractol->img.img_ptr = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
    // if (!fractol->img.img_ptr)
    // {
    //     mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
    //     mlx_destroy_image(fractol->mlx_ptr, fractol->mlx_win);
    //     error();
    // }
    fractol->img.img_pixels = mlx_get_data_addr(&fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
    // if(!fractol->img.img_pixels)
    // {
    //     mlx_destroy_window(fractol->mlx_ptr, fractol->mlx_win);
    //     mlx_destroy_image(fractol->mlx_ptr, fractol->mlx_win);
    //     // free(fractol->mlx_ptr);
    //     error();
    // }
}
