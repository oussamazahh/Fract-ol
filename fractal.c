/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:35:09 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/31 23:23:40 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int main(int ac, char *av[])
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		t_fractol fractol;
		fractol.name = "Test";
		my_intit_mlx(&fractol);
		mlx_put_image_to_window(fractol.mlx_ptr, fractol.mlx_win, fractol.img.img_ptr, 0, 0);
		mlx_loop(fractol.mlx_ptr);
	}
	else
		write(1, "Try to study bro!!", 18);
	return (0);
}