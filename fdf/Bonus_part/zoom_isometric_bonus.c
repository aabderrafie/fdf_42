/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_isometric_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:44:19 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:26:47 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom(t_point *point, double factor)
{
	point->x *= factor;
	point->y *= factor;
	if (point->z >= 45 || point->z <= -30)
		point->z *= 1;
	else
		point->z *= factor;
}

void	isometric(t_point *point)
{
	rotate_x(point, -45 * M_PI / 180);
	rotate_y(point, -35 * M_PI / 180);
	rotate_z(point, 30 * M_PI / 180);
}

void	apply_transformations(t_point *p, t_vars vars)
{
	zoom(p, vars.scale);
	rotate_x(p, vars.rotation_angle_x);
	rotate_y(p, vars.rotation_angle_y);
	rotate_z(p, vars.rotation_angle_z);
	isometric(p);
	translate(p, vars.translate_x, vars.translate_y);
}
