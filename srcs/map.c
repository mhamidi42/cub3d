/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:14:11 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 18:42:47 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_format(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(data->fd);
	while (i < len)
	{
		if (data->fd[len - 1] != 'b' || data->fd[len - 2] != 'u'
			|| data->fd[len - 3] != 'c' || data->fd[len - 4] != '.')
			close_game(data, "Wrong map format");
		i++;
	}
}

int	map_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		data->key_pressed[i] = 0;
		i++;
	}
	check_format(data);
	return (0);
}
