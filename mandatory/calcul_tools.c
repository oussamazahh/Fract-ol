/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:27:01 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 18:29:55 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	data_int_j(t_fractol *fractol, double x, double y)
{
	fractol->julia_x = x;
	fractol->julia_y = y;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] - s2[i] > 0)
			return (1);
		if (s1[i] - s2[i] < 0)
			return (-1);
		i++;
	}
	return (0);
}

static void	add_to_number(double *n, const char *str, double *fraction, int *i)
{
	(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*n += (str[*i] - '0') * (*fraction);
		*fraction /= 10;
		(*i)++;
	}
}

double	ft_atod(const char *str)
{
	int		i;
	int		sign;
	double	n;
	double	fraction;

	i = 0;
	n = 0;
	fraction = 0.1;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		add_to_number(&n, str, &fraction, &i);
	return (n * sign);
}

void	error_msg(void)
{
	write(2, "error in malloc", 15);
	exit(1);
}
