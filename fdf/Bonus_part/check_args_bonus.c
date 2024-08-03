/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:31:15 by aaskal            #+#    #+#             */
/*   Updated: 2024/05/07 15:48:40 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	is_string_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]) || !ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	get_length(char **str)
{
	int	i;
	int	len;

	if (!str)
		return (0);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (is_string_num(str[i]))
			len++;
		i++;
	}
	return (len);
}

void	process_first_line(t_index *index, int fd)
{
	index->i = 0;
	index->j = 0;
	index->line = get_next_line(fd);
	index->nums = ft_split(index->line, ' ');
	index->j = get_length(index->nums);
	if (index->j == 0)
		ft_error(" The map is empty. Exiting.\n");
	free_all(index->line, index->nums);
	index->line = NULL;
	index->nums = NULL;
}

void	process_other_lines(t_index *index, int fd)
{
	index->line = get_next_line(fd);
	while (index->line)
	{
		index->i = 0;
		index->nums = ft_split(index->line, ' ');
		index->i = get_length(index->nums);
		if (index->i != index->j)
			ft_error("Found wrong line length. Exiting.\n");
		free_all(index->line, index->nums);
		index->line = NULL;
		index->nums = NULL;
		index->line = get_next_line(fd);
	}
}

void	check_args(char *filename)
{
	int		fd;
	t_index	index;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Invalid file\n");
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".fdf", 4))
		ft_error("Invalid file extension\n");
	process_first_line(&index, fd);
	process_other_lines(&index, fd);
	close(fd);
}
