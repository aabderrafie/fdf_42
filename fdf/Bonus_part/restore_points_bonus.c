/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_points_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:31:04 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/08 13:13:16 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_point3d	**copy_points(t_point3d **points, t_mapsize size)
{
	t_point3d	**copy;
	int			i;
	int			j;

	i = 0;
	copy = malloc(sizeof(t_point3d *) * size.height);
	while (i < size.height)
	{
		copy[i] = malloc(sizeof(t_point3d) * size.width);
		j = 0;
		while (j < size.width)
		{
			copy[i][j] = points[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

void	restore_points(t_point3d **points, t_point3d **original_points,
		t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.size.height)
	{
		j = 0;
		while (j < vars.size.width)
		{
			points[i][j] = original_points[i][j];
			if (vars.check == 1)
				points[i][j].color = change_colors(vars.original_points[i][j].z,
						vars.low_color, vars.high_color);
			j++;
		}
		i++;
	}
}

void	parallel(t_point3d **points, t_mapsize size, t_vars vars)
{
	int	i;
	int	j;

	(void)vars;
	i = 0;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			points[i][j].z = 0;
			if (vars.check == 1)
				points[i][j].color = change_colors(vars.original_points[i][j].z,
						vars.low_color, vars.high_color);
			j++;
		}
		i++;
	}
}
