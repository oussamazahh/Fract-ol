/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:48:02 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 18:00:17 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal_bonus.h"

static double	ft_abs(double d)
{
	if (d < 0.0)
		d *= -1;
	return (d);
}

t_complex	square_complex_burnin(t_complex z)
{
	t_complex	tmp;

	tmp.x = (z.x * z.x) - (z.y * z.y);
	tmp.y = ft_abs(2 * z.x * z.y);
	return (tmp);
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
	tmp.y = 2 * z.x * z.y;
	return (tmp);
}
