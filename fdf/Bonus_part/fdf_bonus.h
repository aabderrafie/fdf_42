/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:00:57 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 14:24:54 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define LOW_COLOR 0x7FFF12
# define HIGH_COLOR 0x808000

# define WIDTH 1920
# define HEIGHT 1300
# define ESC_KEY 53
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define DOWN_ARROW_KEY 125
# define UP_ARROW_KEY 126
# define PLUS_KEY 69
# define MINUS_KEY 78
# define R_KEY 15
# define L_KEY 37
# define D_KEY 2
# define U_KEY 32
# define Z_KEY 6
# define P_KEY 35
# define Q_KEY 12
# define W_KEY 13
# define C_KEY 8
# define G_KEY 5
# define O_KEY 31
# define BACKSLASH_KEY 42
# define M_KEY 46
# define S_KEY 1
# define Z 0

typedef struct s_dda
{
	double		dx;
	double		dy;
	double		steps;
	double		xinc;
	double		yinc;
	double		x;
	double		y;
	int			color;
}				t_dda;

typedef struct s_index
{
	int			x;
	int			y;
	char		*line;
	char		**nums;
	char		**values;
	int			scale_factor;
	int			i;
	int			j;
	int			k;
	int			color;
	char		*l;

}				t_index;

typedef struct s_point3d
{
	double		x;
	double		y;
	int			z;
	int			color;
}				t_point3d;

typedef struct s_mapsize
{
	int			width;
	int			height;
}				t_mapsize;

typedef struct s_point
{
	double		x;
	double		y;
	int			z;
	int			color;
}				t_point;

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_rgb
{
	int			low_red;
	int			low_green;
	int			low_blue;
	int			high_red;
	int			high_green;
	int			high_blue;
	double		ratio;

}				t_rgb;

typedef struct s_vars
{
	t_point3d	**points;
	t_mapsize	size;
	t_index		index;
	void		*mlx_ptr;
	void		*win_ptr;
	double		rotation_angle_x;
	double		rotation_angle_y;
	double		rotation_angle_z;
	double		scale;
	int			color;
	double		translate_x;
	double		translate_y;
	int			parallel;
	t_point3d	**original_points;
	t_img		img;
	int			low_color;
	int			high_color;
	int			check;
	int			slash;

}				t_vars;

t_mapsize		get_map_size(char *filename);
void			draw_line(t_vars vars, t_point p1, t_point p2);
void			mlx_functions(t_vars *vars);
int				hex_to_int(char *hex);
t_point3d		**parse_map(char *filename, t_vars *vars);

void			rotate_x(t_point *point, float theta);
void			rotate_y(t_point *point, float theta);
void			rotate_z(t_point *point, float theta);
void			draw_map(t_point3d **points, t_vars vars);
void			zoom(t_point *point, double scale);

void			translate(t_point *point, double x, double y);
void			parallel(t_point3d **points, t_mapsize size, t_vars vars);
void			restore_points(t_point3d **points, t_point3d **original_points,
					t_vars vars);
t_point3d		**copy_points(t_point3d **points, t_mapsize size);
int				get_gradient(int low, int high, int current, int max);

void			handle_arrow_zoom(int keycode, t_vars *vars);
void			handle_rlud_keys(int keycode, t_vars *vars);
void			handle_zwpq_slash_keys(int keycode, t_vars *vars);
void			handle_c_key(int keycode, t_vars *vars);
void			handle_o_esc_key(int keycode, t_vars *vars);
void			my_mlx_pixel_put(t_img *image, int x, int y, int color);
int				change_colors(int z, int low_color, int high_color);

void			fill_points(int fd, t_point3d **points, t_vars *vars);
t_point3d		**allocate_points(char *filename, t_mapsize size);
void			free_all(char *line, char **nums);
void			display_key_usage(t_vars *vars);
void			apply_transformations(t_point *p, t_vars vars);
void			check_args(char *filename);
void			ft_error(char *message);
void			free_points(t_point3d **points, t_vars vars);
double			get_scale(t_mapsize size);

#endif
