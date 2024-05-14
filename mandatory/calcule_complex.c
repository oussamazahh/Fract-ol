/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:28:39 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 14:28:10 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

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
