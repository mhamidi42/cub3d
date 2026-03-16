/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:36:59 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/18 19:18:19 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*skip_empty_lines(int fd, int *i)
{
	char	*line;

	line = get_next_line(fd);
	while (line && handle_empty_line(line) == 0)
	{
		free(line);
		(*i)++;
		line = get_next_line(fd);
	}
	return (line);
}

int	get_map_start_index(char *filename)
{
	char	*line;
	int		fd;
	int		index;
	int		i;

	index = -1;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("Error: Cannot open file\n"), -1);
	line = skip_empty_lines(fd, &i);
	while (line)
	{
		if (str_is_map(line) == 0 && index == -1)
			index = i;
		free(line);
		i++;
		line = skip_empty_lines(fd, &i);
	}
	close(fd);
	return (index);
}

void	map_line(char *line, int *width_max, int *height_max)
{
	int	len;

	len = ft_strlen(line);
	if (handle_empty_line(line) == 0)
	{
		free(line);
		return ;
	}
	if (len > *width_max)
		*width_max = len;
	(*height_max)++;
	free(line);
}

void	get_map_size(char *file, int debut_map, int *width_max, int *height_max)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Cannot open file\n");
		return ;
	}
	*width_max = 0;
	*height_max = 0;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i++ < debut_map)
			free(line);
		else
			map_line(line, width_max, height_max);
		line = get_next_line(fd);
	}
	close(fd);
}

void	stock_analyse_map(char *file, t_parsing *parse)
{
	int	index_debut_map;

	if (parse->path_north == NULL || parse->path_south == NULL
		|| parse->path_east == NULL || parse->path_west == NULL
		|| parse->floor[0] <= 0 || parse->cell[0] <= 0)
	{
		printf("Error: With textures or colors\n");
		return ;
	}
	index_debut_map = get_map_start_index(file);
	get_map_size(file, index_debut_map, &parse->map_width, &parse->map_height);
	if ((parse->map_width <= 2) || (parse->map_height == 1))
	{
		printf("Error: map too small\n");
		return ;
	}
	if (allocate_map(parse) == 1)
	{
		parse->map = NULL;
		return ;
	}
	filling_map(file, index_debut_map, parse);
}
