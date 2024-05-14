/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:32:23 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 16:10:22 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

void	clear_draw(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx_ptr, fractol->mlx_win);
	my_intit_mlx(fractol);
}

void	error_msg(void)
{
	write(2, "error in malloc", 15);
	exit(1);
}

void	invalid_input_msg(void)
{
	write (2, "to run <<./fractol_bonus>> Must specify one of fractol\n", 55);
	write (2, "./fractol_bonus Mandelbrot\n", 27);
	write (2, "./fractol_bonus Burning_ship\n", 29);
	write (2, "./fractol_bonus Julia <num1> <num2>\n", 36);
	exit (2);
}
