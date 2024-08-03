/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:37:24 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/07 15:08:27 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rgb	get_rgb(int color)
{
	t_rgb	rgb;

	rgb.low_red = (color >> 16) & 0xFF;
	rgb.low_green = (color >> 8) & 0xFF;
	rgb.low_blue = color & 0xFF;
	return (rgb);
}

int	get_gradient(int low, int high, int current_step, int total_steps)
{
	t_rgb	rgb_low;
	t_rgb	rgb_high;
	int		red;
	int		green;
	int		blue;

	red = 0;
	green = 0;
	blue = 0;
	if (low == high)
		return (low);
	rgb_low = get_rgb(low);
	rgb_high = get_rgb(high);
	if (total_steps != 0)
	{
		red = rgb_low.low_red + (current_step * (rgb_high.low_red
					- rgb_low.low_red) / total_steps);
		green = rgb_low.low_green + (current_step * (rgb_high.low_green
					- rgb_low.low_green) / total_steps);
		blue = rgb_low.low_blue + (current_step * (rgb_high.low_blue
					- rgb_low.low_blue) / total_steps);
	}
	return ((red << 16) | (green << 8) | blue);
}

int	change_colors(int z, int lower, int high)
{
	t_rgb	rgb_low;
	t_rgb	rgb_high;
	int		red;
	int		green;
	int		blue;

	rgb_low = get_rgb(lower);
	rgb_high = get_rgb(high);
	red = (rgb_low.low_red * (1.0 - (double)(z + 10) / 20 * 50))
		+ (rgb_high.low_red * (double)(z + 10) / 20 * 50);
	green = (rgb_low.low_green * (1.0 - (double)(z + 10) / 20 * 50))
		+ (rgb_high.low_green * (double)(z + 10) / 20 * 50);
	blue = (rgb_low.low_blue * (1.0 - (double)(z + 10) / 20 * 50))
		+ (rgb_high.low_blue * (double)(z + 10) / 20 * 50);
	return ((red << 16) | (green << 8) | blue);
}
