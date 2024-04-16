/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractla_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:00:23 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 17:22:26 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

int	loop_hook(t_fractol *fractol)
{
	update_fractal(fractol);
	my_intit_mlx(fractol);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1],
					"Burning_ship"))) || (ac == 4 && !ft_strcmp(av[1],
				"Julia")))
	{
		fractol.name = av[1];
		my_fractol_unit(&fractol);
		if (!ft_strcmp(av[1], "Julia"))
			data_int_j(&fractol, ft_atod(av[2]), ft_atod(av[3]));
		mlx_mouse_hook(fractol.mlx_win, mouse_event, &fractol);
		mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
		mlx_loop_hook(fractol.mlx_ptr, loop_hook, &fractol);
		my_intit_mlx(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
}
