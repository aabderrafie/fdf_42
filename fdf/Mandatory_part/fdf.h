/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:00:57 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:15:09 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
// # include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

# define LOW_COLOR 0x7FFF12
# define HIGH_COLOR 0x808000

# define WIDTH 1000
# define HEIGHT 1300
# define ESC_KEY 53

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
	double		scale;
	int			color;
	t_img		img;
	int			low_color;
	int			high_color;

}				t_vars;

t_mapsize		get_map_size(char *filename);
void			draw_line(t_vars vars, t_point p1, t_point p2);
void			mlx_functions(t_vars *vars);
int				hex_to_int(char *hex);
void			draw_map(t_point3d **points, t_vars vars);
void			zoom(t_point *point, double scale);
int				get_gradient(int low, int high, int current, int max);
void			handle_o_esc_key(int keycode, t_vars *vars);
void			my_mlx_pixel_put(t_img *image, int x, int y, int color);
int				change_colors(int z, int low_color, int high_color);
t_point3d		**parse_map(char *filename, t_vars *vars);
void			fill_points(int fd, t_point3d **points, t_vars *vars);
t_point3d		**allocate_points(char *filename, t_mapsize size);
void			free_all(char *line, char **nums);
void			apply_transformations(t_point *p, t_vars vars);
void			check_args(char *filename);
void			ft_error(char *message);
void			free_points(t_point3d **points, t_vars vars);
double			get_scale(t_mapsize size);
void			rotate_x(t_point *point, float theta);
void			rotate_y(t_point *point, float theta);
void			rotate_z(t_point *point, float theta);

#endif
