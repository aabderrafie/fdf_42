/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:20:35 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/08 15:31:02 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	image->img_ptr = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)image->img_ptr = color;
}

int	key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	close_window(t_vars *vars)
{
	(void)vars;
	exit(0);
}

void	mlx_functions(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIDTH, HEIGHT, "FDF 42");
	mlx_hook(vars->win_ptr, 2, 0, key_hook, vars);
	mlx_hook(vars->win_ptr, 17, 0, close_window, vars);
}
