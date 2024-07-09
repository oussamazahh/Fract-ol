/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:15:29 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/16 20:41:18 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static void	help_destroy(t_fractol *fractol)
{
	mlx_clear_window(fractol->mlx_ptr, fractol->mlx_win);
	my_intit_mlx(fractol);
}

int	mouse_event(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom *= 0.95;
		help_destroy(fractol);
		return (1);
	}
	else if (button == 5)
	{
		fractol->zoom *= 1.05;
		help_destroy(fractol);
		return (1);
	}
	else
		return (0);
	return (0);
}
