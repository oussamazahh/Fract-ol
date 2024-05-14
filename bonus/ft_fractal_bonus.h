/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:30:18 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 18:09:00 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_BONUS_H
# define FT_FRACTAL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

# define WHITE 0xFFFFFF
# define ECHAP 53
# define LEFT 124
# define UP 126
# define RIGHT 123
# define DOWN 125
# define PLUS 69
# define MIN 78

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
	int		width;
	int		height;
	double	center_x;
	double	center_y;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	x_pos_min;
	double	x_pos_max;
	double	y_pos_min;
	double	y_pos_max;
}			t_fractol;

/* CALCULE_TOOLS */
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(const char *str);
t_complex	square_complex(t_complex z);
t_complex	square_complex_burnin(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);

/* INITIALIZATION TO CREATE FRACTOL */
void		my_fractol_unit(t_fractol *fractol, char *str);
void		my_intit_mlx(t_fractol *fractol);
void		check_burning(t_fractol *fractol, t_complex *z, t_complex *c);

/* DRAW_TOOLS */
void		my_pixel_put(int x, int y, t_img *img, int color);
void		my_pixel_put_v1(int x, int y, t_img *img, int color);
int			grayscale_color(int i, int max_iter);

/* HOOKS_(KEYS|MOUSE) */
int			key_hook(int key, t_fractol *fractol);
int			mouse_event(int button, int x, int y, t_fractol *fractol);
int			pos_cursor(int x, int y, t_fractol *fractol);
int			close_window(t_fractol *fractol);

/* JULIA SET */
void		data_int_j(t_fractol *fractol, double x, double y);
void		juila_int(t_fractol *fractol, t_complex *z, t_complex *c);

/* CHECKING INPUTS */
int			check_correct_nbr(char **av);
int			is_space_sign(char c, int h);
int			ft_isdigit(int c);

/* EXTRA */
void		clear_draw(t_fractol *fractol);
void		invalid_input_msg(void);
void		error_msg(void);
#endif