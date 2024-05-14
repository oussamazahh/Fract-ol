/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:00:40 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/14 18:00:41 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_H
# define FT_FRACTAL_H

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
	int		color_gradient;
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

/* CALCULE_TOOLS */
int			ft_strcmp(char *s1, char *s2);
double		ft_atod(const char *str);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

/* INITIALIZATION TO CREATE FRACTOL */
void		my_fractol_unit(t_fractol *fractol);
void		my_intit_mlx(t_fractol *fractol);
void		data_int(t_fractol *fractol);

/* DRAW_TOOLS */
void		my_pixel_put_v1(int x, int y, t_img *img, int color);
void		my_pixel_put(int x, int y, t_img *img, int color);
int			grayscale_color(int i, int max_iter);

/* HOOKS_(KEYS|MOUSE) */
int			mouse_event(int button, int x, int y, t_fractol *fractol);
int			key_hook(int key, t_fractol *fractol);
int			close_window(t_fractol *fractol);

/* JULIA SET */
void		juila_int(t_fractol *fractol, t_complex *z, t_complex *c);
void		data_int_j(t_fractol *fractol, double x, double y);

/* CHECKING INPUTS */
int			check_correct_nbr(char **av);
int			is_space_sign(char c, int h);
int			ft_isdigit(int c);

/* EXTRA */
void		clear_draw(t_fractol *fractol);
void		invalid_input_msg(void);
void		error_msg(void);
#endif