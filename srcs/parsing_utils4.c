/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:10:13 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/18 21:21:52 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	validate_and_clean_parsing(int parsing_status, t_parsing *parse)
{
	char	*line;

	line = NULL;
	if (parsing_status < 0)
		return (1);
	if (parsing_status > 0)
	{
		free_parsing(parse);
		line = get_next_line(parsing_status);
		while (line != NULL)
		{
			free(line);
			line = get_next_line(parsing_status);
		}
		return (1);
	}
	return (0);
}

int	validate_map_structure(t_parsing *parse)
{
	if (parse->map_height == 1)
	{
		free_dbl_array(parse->map);
		free_parsing(parse);
		return (1);
	}
	if (parse->map == NULL)
	{
		if (parse->path_north == NULL || parse->path_south == NULL
			|| parse->path_east == NULL || parse->path_west == NULL
			|| parse->floor[0] < 0 || parse->cell[0] < 0)
		{
			free_dbl_array(parse->map);
			free_parsing(parse);
			return (1);
		}
		printf("Error:  No map\n");
		free_dbl_array(parse->map);
		free_parsing(parse);
		return (1);
	}
	return (0);
}

int	handle_parsing(char *filename, t_parsing *parse)
{
	int	parsing_status;

	parsing_status = parsing(filename, parse);
	if (validate_and_clean_parsing(parsing_status, parse))
		return (1);
	if (parse->map_started == 1)
		stock_analyse_map(filename, parse);
	if (validate_map_structure(parse))
		return (1);
	replace_spaces_with_x(parse->map);
	if (is_map_invalid(parse) == 1)
	{
		free_dbl_array(parse->map);
		free_parsing(parse);
		return (1);
	}
	replace_spaces_with_one(parse->map);
	return (0);
}

int	validate_and_skip_prefix(char *str, char c, char d, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == c && str[*i + 1] == d && str[*i + 2] == ' ')
		*i += 3;
	else
		return (0);
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != '.' || str[*i + 1] != '/')
		return (0);
	return (1);
}

char	*parse_texture_path(char *str, char c, char d)
{
	char	*path;
	int		start;
	int		end;

	int (j) = 0;
	int (i) = 0;
	if (!validate_and_skip_prefix(str, c, d, &i))
		return (NULL);
	start = i;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
		i++;
	end = i;
	while (str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] != '\0')
		return (NULL);
	path = malloc(sizeof(char) * (end - start + 1));
	if (!path)
		return (NULL);
	while (start < end)
		path[j++] = str[start++];
	path[j] = '\0';
	return (path);
}
