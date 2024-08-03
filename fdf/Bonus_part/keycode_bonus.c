/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:01:34 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/07 15:49:03 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	handle_arrow_zoom(int keycode, t_vars *vars)
{
	if (keycode == LEFT_ARROW_KEY)
		vars->rotation_angle_x -= 0.2;
	else if (keycode == RIGHT_ARROW_KEY)
		vars->rotation_angle_x += 0.2;
	else if (keycode == DOWN_ARROW_KEY)
		vars->rotation_angle_y += 0.2;
	else if (keycode == UP_ARROW_KEY)
		vars->rotation_angle_y -= 0.2;
	else if (keycode == PLUS_KEY)
		vars->scale += 1.0;
	else if (keycode == MINUS_KEY)
	{
		if (vars->scale > 1.0)
			vars->scale -= 1.0;
	}
}

void	handle_rlud_keys(int keycode, t_vars *vars)
{
	if (keycode == R_KEY)
		vars->translate_x += 10;
	else if (keycode == L_KEY)
		vars->translate_x -= 10;
	else if (keycode == D_KEY)
		vars->translate_y += 10;
	else if (keycode == U_KEY)
		vars->translate_y -= 10;
}

void	handle_zwpq_slash_keys(int keycode, t_vars *vars)
{
	if (keycode == Z_KEY)
		vars->rotation_angle_z += 0.2;
	else if (keycode == W_KEY)
		vars->rotation_angle_z -= 0.2;
	else if (keycode == P_KEY)
		vars->parallel = 1;
	else if (keycode == Q_KEY)
		vars->parallel = 0;
	else if (keycode == BACKSLASH_KEY)
	{
		if (vars->slash == 0)
			vars->slash = 1;
		else
			vars->slash = 0;
	}
}

void	handle_c_key(int keycode, t_vars *vars)
{
	t_rgb	rgb;
	int		cooor_1;
	int		cooor_2;

	if (keycode == C_KEY)
	{
		vars->check = 1;
		rgb.low_red = (vars->low_color >> 16) & 0xFF;
		rgb.low_green = (vars->low_color >> 8) & 0xFF;
		rgb.low_blue = vars->low_color & 0xFF;
		rgb.high_red = (vars->high_color >> 16) & 0xFF;
		rgb.high_green = (vars->high_color >> 8) & 0xFF;
		rgb.high_blue = vars->high_color & 0xFF;
		rgb.low_red += 10;
		rgb.low_green += 10;
		rgb.low_blue += 20;
		rgb.high_red -= 10;
		rgb.high_green -= 10;
		rgb.high_blue -= 5;
		cooor_1 = (rgb.low_red << 16) | (rgb.low_green << 8) | rgb.low_blue;
		cooor_2 = (rgb.high_red << 16) | (rgb.high_green << 8) | rgb.high_blue;
		vars->low_color = cooor_1;
		vars->high_color = cooor_2;
	}
}

void	handle_o_esc_key(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	else if (keycode == O_KEY)
	{
		vars->rotation_angle_x = 0;
		vars->rotation_angle_y = 0;
		vars->rotation_angle_z = 0;
		vars->translate_x = 0;
		vars->translate_y = 0;
		vars->parallel = 0;
		vars->low_color = LOW_COLOR;
		vars->high_color = HIGH_COLOR;
		vars->check = 0;
		vars->slash = 1;
		vars->scale = get_scale(vars->size);
	}
}
