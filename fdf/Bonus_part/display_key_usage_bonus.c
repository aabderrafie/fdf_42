/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_key_usage_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:35:14 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/07 15:48:50 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	display_message(t_vars *vars, char *message, int y, int color)

{
	mlx_string_put(vars->mlx_ptr, vars->win_ptr, 30, y, color, message);
}

void	display_key_usage(t_vars *vars)
{
	int	offset;
	int	color;

	color = 0x008080;
	offset = -1;
	while (offset <= 0)
	{
		display_message(vars, " ------  Key usage  ------ ", 40, 0xFF7F50);
		display_message(vars, "  Arrow keys : Rotate", 70, color);
		display_message(vars, "  ESC : Exit", 100, color);
		display_message(vars, "  + : Zoom in", 130, color);
		display_message(vars, "  - : Zoom out", 160, color);
		display_message(vars, "  R : Move right", 190, color);
		display_message(vars, "  L : Move left", 220, color);
		display_message(vars, "  U : Move up", 250, color);
		display_message(vars, "  D : Move down", 280, color);
		display_message(vars, "  Z : Rotate Z axis", 310, color);
		display_message(vars, "  W : Rotate reverse Z axis", 340, color);
		display_message(vars, "  P : Parallel projection", 370, color);
		display_message(vars, "  Q : Perspective projection", 400, color);
		display_message(vars, "  C : Change color", 430, color);
		display_message(vars, "  O : Reset", 460, color);
		display_message(vars, "  \\ : Diagonal", 490, color);
		offset++;
	}
}
