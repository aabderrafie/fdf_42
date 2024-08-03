/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:16:30 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:03:39 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_point_values(t_point3d **points, t_index i, t_vars *vars)
{
	(void)vars;
	i.values = ft_split(i.nums[i.x], ',');
	points[i.y][i.x].x = i.x;
	points[i.y][i.x].y = i.y;
	points[i.y][i.x].z = ft_atoi(i.values[0]);
	i.color = change_colors(points[i.y][i.x].z, vars->low_color,
			vars->high_color);
	if (i.values[1])
		points[i.y][i.x].color = hex_to_int(i.values[1]);
	else
		points[i.y][i.x].color = i.color;
	free_all(NULL, i.values);
	i.values = NULL;
}

void	intialise_vars(t_vars *vars, t_mapsize size, t_point3d **points)
{
	vars->points = points;
	vars->low_color = LOW_COLOR;
	vars->high_color = HIGH_COLOR;
	vars->size = size;
	vars->scale = get_scale(size);
}

t_point3d	**allocate_points(char *filename, t_mapsize size)
{
	int			fd;
	t_point3d	**points;
	int			i;

	i = 0;
	fd = open(filename, O_RDONLY);
	points = malloc(sizeof(t_point3d *) * size.height);
	if (!points)
		ft_error("Memory allocation failed\n");
	while (i < size.height)
	{
		points[i] = malloc(sizeof(t_point3d) * size.width);
		if (!points[i])
			ft_error("Memory allocation failed\n");
		i++;
	}
	return (points);
}

void	fill_points(int fd, t_point3d **points, t_vars *vars)
{
	t_index	i;

	i.y = 0;
	i.line = get_next_line(fd);
	while (i.line != NULL)
	{
		i.nums = ft_split(i.line, ' ');
		i.x = 0;
		while (i.nums[i.x] != NULL)
		{
			assign_point_values(points, i, vars);
			i.x++;
		}
		free_all(i.line, i.nums);
		i.nums = NULL;
		i.line = NULL;
		i.line = get_next_line(fd);
		i.y++;
	}
}

t_point3d	**parse_map(char *filename, t_vars *vars)
{
	t_mapsize	size;
	t_point3d	**points;
	int			fd;

	size = get_map_size(filename);
	points = allocate_points(filename, size);
	intialise_vars(vars, size, points);
	fd = open(filename, O_RDONLY);
	fill_points(fd, points, vars);
	close(fd);
	return (points);
}
