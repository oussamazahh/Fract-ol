/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:00:40 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 18:39:00 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_H
# define FT_FRACTAL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
# define DARK_BLUE 0x00008B
# define ECHAP 53
# define LEFT 124
# define UP 126
# define RIGHT 123
# define DOWN 125
# define PLUS 69
# define MIN 78
# define CULTURED_COLOR 0xF9F9F8
# define PLATINUM_COLOR 0xE5E6E4
# define TKHERBIQA 0xC2C8C5

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
	double	target_zoom;
	int		color;
	double	target_shift_x;
	double	target_shift_y;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
}			t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

int			ft_strcmp(char *s1, char *s2);
void		my_intit_mlx(t_fractol *fractol);
double		ft_atod(const char *str);
t_complex	square_complex_burnin(t_complex z);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
void		my_fractol_unit(t_fractol *fractol);
void		error_msg(void);
void		my_pixel_put(int x, int y, t_img *img, int color);
// int			grayscale_color(int i, int max_iter);
void		my_pixel_put(int x, int y, t_img *img, int color);
// void		my_mouse_hook(t_fractol *fractol);
int			key_hook(int key, t_fractol *fractol);
void		juila_int(t_fractol *fractol, t_complex *z, t_complex *c);
// int			color_change(int key, t_fractol *fractol);
// void		my_intit_mlx_j(t_fractol *fractol, char *s1, char *s2);
void		data_int_j(t_fractol *fractol, double x, double y);
int			mouse_event(int button, int x, int y, t_fractol *fractol);
int			grayscale_color(int i, int max_iter);
// int			julia_ret(int x, int y, t_fractol *fractol);
void		update(t_fractol *fractol);
void		data_int(t_fractol *fractol);
#endif