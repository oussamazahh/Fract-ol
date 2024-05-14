/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:01:35 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 15:42:49 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	error_msg(void)
{
	write(2, "error in malloc", 15);
	exit(1);
}

void	clear_draw(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx_ptr, fractol->mlx_win);
	my_intit_mlx(fractol);
}

void	invalid_input_msg(void)
{
	write (2, "to run <<./fractol>> Must specify one of fractol\n", 49);
	write (2, "./fractol Mandelbrot\n", 21);
	write (2, "./fractol Julia <num1> <num2>\n", 29);
	exit (2);
}
