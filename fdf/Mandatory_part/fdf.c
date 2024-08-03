/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:18 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/09 13:32:21 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	free_points(t_point3d **points, t_vars vars)
{
	int	i;

	i = 0;
	while (i < vars.size.height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}

int	hex_to_int(char *hex)
{
	int	result;

	result = 0;
	while (*hex)
	{
		result *= 16;
		if (*hex >= '0' && *hex <= '9')
			result += *hex - '0';
		else if (*hex >= 'a' && *hex <= 'f')
			result += *hex - 'a' + 10;
		else if (*hex >= 'A' && *hex <= 'F')
			result += *hex - 'A' + 10;
		hex++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_point3d	**points;
	char		*filename;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <filename>\n", 2);
		exit(1);
	}
	filename = argv[1];
	check_args(argv[1]);
	points = parse_map(filename, &vars);
	mlx_functions(&vars);
	draw_map(points, vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
