/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:16 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:27:48 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	create_point(t_point3d **points, int i, int j, t_vars vars)
{
	t_point	p;
	int		with;
	int		height;

	with = (vars.size.width) / 2;
	height = (vars.size.height) / 2;
	p = (t_point){points[i][j].x - with, points[i][j].y - height,
		points[i][j].z, points[i][j].color};
	return (p);
}

void	draw_vertical_lines(t_point3d **points, t_vars vars, int i, int j)
{
	t_point	p1;
	t_point	p2;

	if (i < vars.size.height && j < vars.size.width)
	{
		p1 = create_point(points, i, j, vars);
		if (i + 1 < vars.size.height)
		{
			p2 = create_point(points, i + 1, j, vars);
			draw_line(vars, p1, p2);
		}
	}
}

void	draw_horizontal_lines(t_point3d **points, t_vars vars, int i, int j)
{
	t_point	p1;
	t_point	p2;

	if (i < vars.size.height && j < vars.size.width)
	{
		p1 = create_point(points, i, j, vars);
		if (j + 1 < vars.size.width)
		{
			p2 = create_point(points, i, j + 1, vars);
			draw_line(vars, p1, p2);
		}
	}
}

void	draw_map(t_point3d **points, t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img_ptr,
			&vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	while (i < vars.size.height)
	{
		j = 0;
		while (j <= vars.size.width)
		{
			draw_vertical_lines(points, vars, i, j);
			draw_horizontal_lines(points, vars, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img.img_ptr, 0,
		100);
	mlx_destroy_image(vars.mlx_ptr, vars.img.img_ptr);
}
