/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:00:23 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 18:13:03 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 1 || ac > 4)
		invalid_input_msg();
	if (!ft_strcmp(av[1], "Julia") && check_correct_nbr(av + 1))
	{
		write(2, "Error", 5);
		exit(1);
	}
	if ((ac == 2 && (!ft_strcmp(av[1], "Mandelbrot") || !ft_strcmp(av[1],
					"Burning_ship"))) || (ac == 4 && !ft_strcmp(av[1],
				"Julia")))
	{
		my_fractol_unit(&fractol, av[1]);
		if (!ft_strcmp(av[1], "Julia"))
			data_int_j(&fractol, ft_atod(av[2]), ft_atod(av[3]));
		mlx_mouse_hook(fractol.mlx_win, mouse_event, &fractol);
		mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
		mlx_hook(fractol.mlx_win, 6, 1L << 6, pos_cursor, &fractol);
		mlx_hook(fractol.mlx_win, 17, 1L << 17, close_window, &fractol);
		my_intit_mlx(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
		invalid_input_msg();
}
