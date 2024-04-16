/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:30:18 by ozahidi           #+#    #+#             */
/*   Updated: 2024/04/15 17:56:35 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_BONUS_H
# define FT_FRACTAL_BONUS_H

# include <mlx.h>
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
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

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
	double	julia_x;
	double	julia_y;
	double	target_zoom;
	double	target_shift_x;
	double	target_shift_y;
	double	target_iteration;
	double	tool_x;
	double	tool_y;
}			t_fractol;

int			ft_strcmp(char *s1, char *s2);
void		my_intit_mlx(t_fractol *fractol);
double		ft_atod(const char *str);
t_complex	square_complex(t_complex z);
t_complex	square_complex_burnin(t_complex z);
void		update_fractal(t_fractol *fractol);
t_complex	sum_complex(t_complex z1, t_complex z2);
void		my_fractol_unit(t_fractol *fractol);
void		my_pixel_put(int x, int y, t_img *img, int color);

int			grayscale_color(int i, int max_iter);
// void		my_mouse_hook(t_fractol *fractol);
void		error_msg(void);
void		my_pixel_put1(int x, int y, t_img *img, int color);
int			key_hook(int key, t_fractol *fractol);
// int			color_change(int key, t_fractol *fractol);
// void		my_intit_mlx_j(t_fractol *fractol, char *s1, char *s2);
void		data_int_j(t_fractol *fractol, double x, double y);
void		juila_int(t_fractol *fractol, t_complex *z, t_complex *c);
int			mouse_event(int button, int x, int y, t_fractol *fractol);
// int			julia_ret(int x, int y, t_fractol *fractol);

#endif