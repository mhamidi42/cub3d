/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:46:47 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/18 18:28:07 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	space_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	check_rgb_format(char **rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (space_in_str(rgb[i]) == 1)
		{
			printf("Error\nSpace between in number\n");
			free_dbl_array(rgb);
			return (1);
		}
		i++;
	}
	return (0);
}

int	validate_rgb_values(char **rgb, int *color)
{
	int	i;
	int	value;

	i = 0;
	while (i < 3)
	{
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255)
		{
			printf("Error\nInvalid color value: %d\n", value);
			free_dbl_array(rgb);
			return (1);
		}
		color[i] = value;
		i++;
	}
	return (0);
}

int	parse_color(char *line, int *color, char c)
{
	int		count;
	char	**rgb;
	int		i;

	i = 0;
	while (line[i] == c || line[i] == ' ')
		i++;
	rgb = ft_split(line + i, ',');
	count = count_elements(rgb);
	if (count != 3)
		return (printf("Error: Element color not 3\n"), free_dbl_array(rgb), 1);
	if (check_rgb_format(rgb) || validate_rgb_values(rgb, color))
		return (1);
	free_dbl_array(rgb);
	return (0);
}

void	print_map(char **map)
{
	int (i) = 0;
	if (!map)
		return ;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}
