/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:09:49 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/18 18:54:23 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	count_and_set_player(t_parsing *parse, int i, int j, int *player_count)
{
	char	c;

	c = parse->map[i][j];
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		(*player_count)++;
		parse->player_char = c;
		parse->player_x = j;
		parse->player_y = i;
	}
	return (*player_count);
}

int	check_player_pos(t_parsing *parse)
{
	int	j;

	int (player_count) = 0;
	int (i) = 0;
	while (i < parse->map_height)
	{
		j = 0;
		while (j < parse->map_width)
		{
			count_and_set_player(parse, i, j, &player_count);
			j++;
		}
		i++;
	}
	if (player_count == 0)
		return (printf("Error: No player in the map\n"), 1);
	if (player_count > 1)
		return (printf("Error: Too much players in the map\n"), 1);
	return (0);
}

int	player_can_move(t_parsing *parse)
{
	int	x;
	int	y;

	x = parse->player_x;
	y = parse->player_y;
	if (y - 1 >= 0 && parse->map[y - 1][x] != '1')
		return (0);
	if (y + 1 < parse->map_height && parse->map[y + 1][x] != '1')
		return (0);
	if (x - 1 >= 0 && parse->map[y][x - 1] != '1')
		return (0);
	if (x + 1 < parse->map_width && parse->map[y][x + 1] != '1')
		return (0);
	printf("Error: Player is surrounded by walls!\n");
	return (1);
}

int	is_map_invalid(t_parsing *parse)
{
	if (check_0_adjacent(parse) == 1)
		return (printf("Error: Map invalid: a 0 touch a empty space\n"), 1);
	if (check_first_last_line(parse) == 1)
		return (printf("Error: Map invalid: 1er ou dernier ligne\n"), 1);
	if (check_first_last_char_from_line(parse) == 1)
	{
		printf("Error: Map invalid\n");
		return (1);
	}
	if (check_player_pos(parse) == 1)
		return (1);
	if (player_can_move(parse) == 1)
		return (1);
	return (0);
}
