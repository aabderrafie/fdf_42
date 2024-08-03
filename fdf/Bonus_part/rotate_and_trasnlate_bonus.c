/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_trasnlate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:44:34 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:00:23 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translate(t_point *point, double x, double y)
{
	point->x += x;
	point->y += y;
	point->z += 0;
}

void	rotate_x(t_point *point, float theta)
{
	double	previous_y;
	double	previous_z;

	previous_y = point->y;
	previous_z = point->z;
	point->y = previous_y * cos(theta) + previous_z * sin(theta);
	point->z = -previous_y * sin(theta) + previous_z * cos(theta);
}

void	rotate_y(t_point *point, float theta)
{
	double	previous_x;
	double	previous_z;

	previous_x = point->x;
	previous_z = point->z;
	point->x = previous_x * cos(theta) + previous_z * sin(theta);
	point->z = -previous_x * sin(theta) + previous_z * cos(theta);
}

void	rotate_z(t_point *point, float theta)
{
	double	previous_x;
	double	previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = previous_x * cos(theta) - previous_y * sin(theta);
	point->y = previous_x * sin(theta) + previous_y * cos(theta);
}

void	rotate(t_vars *vars, t_point *point)
{
	rotate_x(point, vars->rotation_angle_x);
	rotate_y(point, vars->rotation_angle_y);
	rotate_z(point, vars->rotation_angle_z);
}
