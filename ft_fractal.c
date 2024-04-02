/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:35:09 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/02 21:29:00 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	main(int ac, char *av[])
{
	int			i;
	t_fractol	fractol;

	if (ac == 2)
	{
		i = 0;
		fractol.name = "Mandelbrot";
		my_intit_mlx(&fractol);
		my_fractol_unit(&fractol);
		mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
		// mlx_loop_hook(fractol.mlx_ptr, color_change, &fractol);
		my_mouse_hook(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
		write(1, "Try to study bro!!", 18);
	return (0);
}
