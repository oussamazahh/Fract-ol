/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:31:02 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/02 12:46:57 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_H
# define FT_FRACTAL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#define XK_KP_Space                      0xff80  /* Space */

# define WIDTH 700
# define HEIGHT 700

# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define MAGENTA 0xFF00FF
# define CYAN 0x00FFFF
# define WHITE 0xFFFFFF
# define DARK_BLUE   0x00008B
# define KEY_ECHAP 53
#define XK_KP_Left  124
#define XK_KP_Up    126
#define XK_KP_Right 123
#define XK_KP_Down  125
#define XK_KP_PLUS  69
#define XK_KP_MIN  78
#define CULTURED_COLOR 0xF9F9F8
#define PLATINUM_COLOR 0xE5E6E4
#define TKHERBIQA 0xC2C8C5

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
	double	value_escap;
	int		iteration;
	double	zoom;
	int		color;
	double	shift_x;
	double	shift_y;
}			t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		my_intit_mlx(t_fractol *fractol);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
void		my_fractol_unit(t_fractol *fractol);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		my_mouse_hook(t_fractol *fractol);
int			key_hook(int key, t_fractol *fractol);
int			color_change(int key, t_fractol *fractol);
#endif