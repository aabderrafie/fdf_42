/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_trasnlate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:44:34 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:00:20 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
