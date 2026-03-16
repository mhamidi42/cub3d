/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:10:19 by mhamidi           #+#    #+#             */
/*   Updated: 2025/03/19 15:54:48 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	which_id(char *str)
{
	int (i) = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (1);
	if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == ' ')
		return (2);
	if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == ' ')
		return (3);
	if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == ' ')
		return (4);
	if (str[i] == 'F' && str[i + 1] == ' ')
		return (5);
	if (str[i] == 'C' && str[i + 1] == ' ')
		return (6);
	return (0);
}

int	count_elements(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i] != NULL)
		i++;
	return (i);
}

int	check_forbidden_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ',' && str[i] != ' ' && str[i] != 'F' && str[i] != 'C'
			&& !(str[i] >= '0' && str[i] <= '9'))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	process_raycasting(t_data *data, t_raycast *ray_c)
{
	variable_init(ray_c);
	calculate_sides(ray_c);
	wall_hit_dda(data, ray_c);
	fill_map(data, ray_c);
}
