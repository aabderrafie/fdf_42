/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:34:45 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/08 15:10:18 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_dda	initialize_dda(t_point p1, t_point p2, t_vars vars)
{
	t_dda	dda;

	apply_transformations(&p1, vars);
	apply_transformations(&p2, vars);
	dda.dx = p2.x - p1.x;
	dda.dy = p2.y - p1.y;
	if (fabs(dda.dx) > fabs(dda.dy))
		dda.steps = fabs(dda.dx);
	else
		dda.steps = fabs(dda.dy);
	if (dda.steps != 0)
	{
		dda.xinc = dda.dx / dda.steps;
		dda.yinc = dda.dy / dda.steps;
	}
	else
	{
		dda.xinc = 0;
		dda.yinc = 0;
	}
	dda.x = p1.x;
	dda.y = p1.y;
	dda.color = p1.color;
	return (dda);
}

void	draw_line(t_vars vars, t_point p1, t_point p2)
{
	t_dda	dda;
	int		i;

	dda = initialize_dda(p1, p2, vars);
	i = 0;
	while (i <= dda.steps && dda.steps != 0)
	{
		if (fabs(dda.dx) >= fabs(dda.dy) && dda.steps != 0)
			p1.color = get_gradient(dda.color, p2.color, i, dda.steps);
		else
		{
			if (dda.steps != 0)
				p1.color = get_gradient(dda.color, p2.color, i, dda.steps);
		}
		if (dda.x + WIDTH / 2 >= 0 && dda.x + WIDTH / 2 < WIDTH && dda.y
			+ HEIGHT / 2 >= 0 && dda.y + HEIGHT / 2 < HEIGHT)
			my_mlx_pixel_put(&vars.img, dda.x + WIDTH / 2, dda.y + HEIGHT / 2,
				p1.color);
		dda.x += dda.xinc;
		dda.y += dda.yinc;
		i++;
	}
}
