/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:31:02 by ozahidi           #+#    #+#             */
/*   Updated: 2024/03/31 21:37:55 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

#define WIDTH 700
#define HEIGHT 700

typedef struct s_img
{
 void *img_ptr;
 char *img_pixels;
 int  bpp;
 int  size_line;
 int  endian;
}    t_img;
typedef struct s_fractol
{
    char    *name;
	void    *mlx_ptr;
	void    *mlx_win;
    t_img   img;
}			t_fractol;

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;


int ft_strncmp(const char *s1, const char *s2, size_t n);
void    my_intit_mlx(t_fractol *fractol);

#endif