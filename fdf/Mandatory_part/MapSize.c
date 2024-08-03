/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapSize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:46:43 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/07 16:24:08 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_scale(t_mapsize size)
{
	double	scale;

	scale = 1;
	if (size.width > 200 || size.height > 200)
		scale = 1;
	else if (size.width >= 100 || size.height >= 100)
		scale = 2.5;
	else if (size.width >= 20 || size.height >= 20)
		scale = 10;
	else
		scale = 20;
	return (scale);
}

void	free_all(char *line, char **nums)
{
	int	i;

	if (line)
		free(line);
	if (nums)
	{
		i = 0;
		while (nums[i])
		{
			free(nums[i]);
			i++;
		}
		free(nums);
	}
}

t_mapsize	get_map_size(char *filename)
{
	t_index		index;
	int			fd;
	t_mapsize	size;

	size.width = 0;
	size.height = 0;
	fd = open(filename, O_RDONLY);
	index.line = get_next_line(fd);
	while (index.line)
	{
		if (size.height == 0)
		{
			index.nums = ft_split(index.line, ' ');
			while (index.nums[size.width] != NULL)
				size.width++;
		}
		free_all(index.line, index.nums);
		index.nums = NULL;
		size.height++;
		index.line = get_next_line(fd);
	}
	close(fd);
	return (size);
}
