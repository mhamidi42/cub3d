/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:10:06 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/18 18:28:47 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	replace_spaces_with_x(char **map)
{
	int	j;

	int (i) = 0;
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == ' ')
				map[i][j] = 'x';
			j++;
		}
		i++;
	}
}

void	replace_spaces_with_one(char **map)
{
	int	j;

	int (i) = 0;
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'x')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	check_0_adjacent(t_parsing *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < parse->map_height)
	{
		j = 0;
		while (j < parse->map_width)
		{
			if (parse->map[i][j] == '0')
			{
				if ((i > 0 && parse->map[i - 1][j] == 'x') ||
					(i < parse->map_height - 1 && parse->map[i + 1][j] == 'x')
					|| (j > 0 && parse->map[i][j - 1] == 'x') ||
					(j < parse->map_width - 1 && parse->map[i][j + 1] == 'x'))
				{
					printf("Error: 0 touch a space in (%d, %d)\n", i, j);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_first_last_line(t_parsing *parse)
{
	int (j) = 0;
	while (j < parse->map_width - 1)
	{
		if (parse->map[0][j] != '1' && parse->map[0][j] != 'x')
		{
			printf("Error: Invalid border in (0, %d)\n", j);
			return (1);
		}
		j++;
	}
	j = 0;
	while (j < parse->map_width - 1)
	{
		if (parse->map[parse->map_height - 1][j] != '1'
			&& parse->map[parse->map_height - 1][j] != 'x')
		{
			printf("Error: Invalid border in (0, %d)\n", j);
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_first_last_char_from_line(t_parsing *parse)
{
	int (j) = 0;
	while (j < parse->map_height)
	{
		if (parse->map[j][0] != '1' && parse->map[j][0] != 'x')
		{
			printf("Error: Invalid border in (%d, 0)\n", j);
			return (1);
		}
		if (parse->map[j][parse->map_width - 2] != '1'
			&& parse->map[j][parse->map_width - 2] != 'x')
		{
			printf("Error: with border in (%d, %d)\n", j, parse->map_width - 2);
			return (1);
		}
		j++;
	}
	return (0);
}
