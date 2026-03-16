/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:24 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/18 21:21:24 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_texture(char *line, t_parsing *parse, char type[2], char **path)
{
	if (parse->map_started == 1)
		return (printf("Error Map before textures/colors\n"), free(line), -1);
	if (*path != NULL)
		return (printf("Error Path doublon\n"), free(line), -1);
	*path = parse_texture_path(line, type[0], type[1]);
	return (0);
}

int	handle_color(char *line, t_parsing *parse, char type, int *color)
{
	if (parse->map_started == 1)
		return (printf("Error Map before textures/colors\n"), free(line), -1);
	if (color[0] != 0)
		return (printf("Error Color doublon\n"), free(line), -1);
	if (check_forbidden_char(line) == 1)
		return (printf("Error char forbidden found in the %c line\n",
				type), free(line), -1);
	if (parse_color(line, color, type) == 1)
		return (free(line), -1);
	return (0);
}

int	process_line_type(char *line, t_parsing *parse, int id)
{
	if (id == 1)
		return (handle_texture(line, parse, "NO", &parse->path_north));
	if (id == 2)
		return (handle_texture(line, parse, "SO", &parse->path_south));
	if (id == 3)
		return (handle_texture(line, parse, "WE", &parse->path_west));
	if (id == 4)
		return (handle_texture(line, parse, "EA", &parse->path_east));
	if (id == 5)
		return (handle_color(line, parse, 'F', parse->floor));
	if (id == 6)
		return (handle_color(line, parse, 'C', parse->cell));
	return (0);
}

int	process_line(char *line, t_parsing *parse, int *map_finished)
{
	int (id) = which_id(line);
	if (id > 0)
		return (process_line_type(line, parse, id));
	if (handle_empty_line(line) == 0)
	{
		if (parse->map_started)
			*map_finished = 1;
	}
	else if (handle_full_line(line) == 1)
		return (free(line), -1);
	else if (str_is_map(line) == 0)
	{
		if (*map_finished)
			return (printf("Error line not empty after end of map\n"),
				free(line), -1);
		parse->map_started = 1;
	}
	return (0);
}

int	parsing(char *filename, t_parsing *parse)
{
	int		fd;
	char	*line;

	int (map_finished) = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error can't open the filename\n"), fd);
	line = get_next_line(fd);
	while (line)
	{
		if (process_line(line, parse, &map_finished) == -1)
		{
			close(fd);
			return (fd);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
