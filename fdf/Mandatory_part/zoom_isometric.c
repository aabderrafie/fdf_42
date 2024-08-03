/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:44:19 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:27:55 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	isometric(p);
}
