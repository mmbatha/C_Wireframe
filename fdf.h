/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 12:02:12 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/10 12:02:11 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "libft/includes/libft.h"

# define DEC_T 100
# define DEC_L 100
# define SIZE_WIDTH 20
# define SIZE_HEIGHT 20

# define WINSIZE_H 750
# define WINSIZE_W 1500

/*
**		Pixel movement
*/
# define MVPIXEL_UP -100
# define MVPIXEL_DN 100
# define MVPIXEL_LT -100
# define MVPIXEL_RT 100

# define MVZOOM_IN 1.1
# define MVZOOM_OUT 0.9

# define ROTATE_X_UP -M_PI / 64
# define ROTATE_X_DN M_PI / 64
# define ROTATE_Y_UP -M_PI / 64
# define ROTATE_Y_DN M_PI / 64
# define ROTATE_Z_UP -M_PI / 64
# define ROTATE_Z_DN M_PI / 64

/*
** 		Key mappings
*/
# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DN 125
# define KEY_LT 123
# define KEY_RT 124

# define KEY_ZOOM_IN 69
# define KEY_ZOOM_OUT 78

# define KEY_ROT_Y_UP 86
# define KEY_ROT_Y_DN 88
# define KEY_ROT_X_DN 91
# define KEY_ROT_X_UP 84
# define KEY_ROT_Z_UP 83
# define KEY_ROT_Z_DN 85

/*
**		Colours
*/

# define RED	0xFF0000
# define GOLD	0xFFD700
# define LIME	0x00FF00
# define BLUE	0x0000FF
# define GREY	0x808080
# define WHITE	0xFFFFFF

typedef struct	s_point
{
	double		x_axis;
	double		y_axis;
	double		z_axis;
	double		size;
	int			z_colour;
}				t_point;

typedef struct	s_line
{
	t_point		**points;
	int			length;
}				t_line;

typedef struct	s_map
{
	t_line		**lines;
	int			length;
}				t_map;

typedef struct	s_scope
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_point		centre;
	void		*image;
	char		*pixel_image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_scope;

typedef struct	s_matrix
{
	double		a1;
	double		a2;
	double		a3;
	double		a4;
	double		b1;
	double		b2;
	double		b3;
	double		b4;
	double		c1;
	double		c2;
	double		c3;
	double		c4;
	double		d1;
	double		d2;
	double		d3;
	double		d4;
}				t_matrix;

/*
** Error handling
** error.c
*/
void			ft_error_malloc(void);
void			ft_error_map(void);
void			ft_error_parse(void);

/*
** Drawing the map
** draw.c
*/

void			ft_create_windows(char *title, int width, int height, t_scope \
		*scope);
void			ft_draw_map(t_scope *scope);

/*
** Extra functions
** helpers.c
*/
int				ft_get_colour(t_point *point1, t_point *point2);
void			ft_get_centre(t_scope *scope);
void			ft_redraw(t_scope *scope);
void			ft_change_map(t_scope *scope);
int				ft_single_point_out(t_point *point);

/*
** Parsing the map
** parse_map.c
*/
t_map			*ft_parse(char **argv, int fd);
int				ft_points(char *line, int break_line, t_point ***points);
int				ft_map_line(char *map);

/*
** Initiate matrices
** matrices.c
*/
t_matrix		*ft_matrix_rotation_x(double axis);
t_matrix		*ft_matrix_rotation_y(double axis);
t_matrix		*ft_matrix_rotation_z(double axis);
t_matrix		*ft_matrix_translation(double t_x, double t_y, double t_z);
t_matrix		*ft_matrix_scale(double size);

/*
** Calculation of matrices
** init_matrices.c
*/
void			ft_calc_rotation(t_scope *scope, double rotation, char axis);
void			ft_calc_translation(t_scope *scope, double x, double y, \
		double z);
void			ft_calc_scale(t_scope *scope, double size);

/*
** Keyboard and mouse events
** keyhook.c and mousehook.c
*/
int				ft_keyhook(int keycode, t_scope *scope);
void			ft_quit(t_scope *scope);
int				ft_mouse_hook(int button, int x, int y, t_scope *scope);
int				ft_set_colour(t_point *point1, t_point *point2);
void			ft_free2d(t_point **points, int length);
void			ft_freelines(t_line **lines, int length);

#endif
