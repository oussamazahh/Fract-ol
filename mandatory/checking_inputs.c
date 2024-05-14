/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_inputs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:54:01 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 16:07:51 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_space_sign(char c, int h)
{
	if (h == 0 && c == '.')
		return (0);
	if ((c == ' ' || c == '\t') || (c == '-' || c == '+') || c == '.')
		return (1);
	return (0);
}

int	check_correct_nbr(char **av)
{
	int	j;
	int	i;
	int	h;

	j = 1;
	while (av[j])
	{
		i = 0;
		h = 0;
		while (av[j][i])
		{
			if (is_space_sign(av[j][i], h) == 0 && ft_isdigit(av[j][i]) == 0)
				return (1);
			if (ft_isdigit(av[j][i]) == 1)
				h++;
			if ((av[j][i] == '-' || av[j][i] == '+') && ft_isdigit(av[j][i
					+ 1]) == 0)
				return (1);
			i++;
		}
		if (h == 0)
			return (1);
		j++;
	}
	return (0);
}
