/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:30:33 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/14 18:04:33 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	allocate_map(t_parsing *parse)
{
	int (i) = 0;
	parse->map = malloc(sizeof(char *) * (parse->map_height + 1));
	if (!parse->map)
	{
		printf("Error: Malloc failed for map\n");
		return (1);
	}
	while (i < parse->map_height)
	{
		parse->map[i] = malloc(sizeof(char) * (parse->map_width + 1));
		if (!parse->map[i])
		{
			printf("Error: Malloc failed for map[%d]\n", i);
			while (--i >= 0)
				free(parse->map[i]);
			free(parse->map);
			return (1);
		}
		i++;
	}
	parse->map[parse->map_height] = NULL;
	return (0);
}

char	*skip_invalid_lines(int fd, int *i, int debut_map)
{
	char	*line;

	line = get_next_line(fd);
	while (line && (*i < debut_map || handle_empty_line(line) == 0))
	{
		free(line);
		(*i)++;
		line = get_next_line(fd);
	}
	return (line);
}

void	fill_map_line(char *line, t_parsing *parse, int j)
{
	int	len;

	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	memset(parse->map[j], ' ', parse->map_width - 1);
	parse->map[j][parse->map_width - 1] = '\0';
	if (len < parse->map_width - 1)
		ft_strncpy(parse->map[j], line, len);
	else
		ft_strncpy(parse->map[j], line, parse->map_width - 1);
}

void	filling_map(char *filename, int debut_map, t_parsing *parse)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ((void)printf("Error: Cannot open file\n"));
	i = 0;
	j = 0;
	line = skip_invalid_lines(fd, &i, debut_map);
	while (line)
	{
		fill_map_line(line, parse, j);
		j++;
		free(line);
		line = skip_invalid_lines(fd, &i, debut_map);
	}
	close(fd);
}
