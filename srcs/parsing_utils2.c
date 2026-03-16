/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:09:58 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/18 18:45:23 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_parsing(t_parsing *parse)
{
	if (parse == NULL)
		return ;
	parse->path_north = NULL;
	parse->path_south = NULL;
	parse->path_west = NULL;
	parse->path_east = NULL;
	parse->floor[0] = 0;
	parse->floor[1] = 0;
	parse->floor[2] = 0;
	parse->cell[0] = 0;
	parse->cell[1] = 0;
	parse->cell[2] = 0;
	parse->player_x = 0;
	parse->player_y = 0;
	parse->player_char = '\0';
	parse->map_started = 0;
	parse->map_height = 0;
	parse->map_width = 0;
	parse->map = NULL;
}

void	free_parsing(t_parsing *parse)
{
	if (parse == NULL)
		return ;
	free(parse->path_north);
	free(parse->path_south);
	free(parse->path_west);
	free(parse->path_east);
	parse->path_north = NULL;
	parse->path_south = NULL;
	parse->path_west = NULL;
	parse->path_east = NULL;
	parse->floor[0] = 0;
	parse->floor[1] = 0;
	parse->floor[2] = 0;
	parse->map_started = 0;
	parse->map_height = 0;
	parse->map_width = 0;
	parse->map = NULL;
	parse->cell[0] = 0;
	parse->cell[1] = 0;
	parse->cell[2] = 0;
	parse->player_x = 0;
	parse->player_y = 0;
	parse->player_char = '\0';
}

int	str_is_map(char *str)
{
	int (i) = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W'
			&& str[i] != ' ' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	handle_full_line(char *str)
{
	if (str_is_map(str) == 1)
	{
		printf("Error Forbidden char detected : %s", str);
		return (1);
	}
	return (0);
}

int	handle_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
