/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:31:33 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 21:02:40 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate_player(t_data *data, double angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = data->dir_x;
	prev_y = data->dir_y;
	if (angle != 0.0)
	{
		data->dir_angle += angle;
		if (data->dir_angle < 0)
			data->dir_angle += 2 * M_PI;
		else if (data->dir_angle >= 2 * M_PI)
			data->dir_angle -= 2 * M_PI;
	}
	data->dir_x = (prev_x * cos(angle)) - (prev_y * sin(angle));
	data->dir_y = (prev_x * sin(angle)) + (prev_y * cos(angle));
	prev_x = data->plane_x;
	prev_y = data->plane_y;
	data->plane_x = (prev_x * cos(angle)) - (prev_y * sin(angle));
	data->plane_y = (prev_x * sin(angle)) + (prev_y * cos(angle));
}

void	move_player(t_data *data, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = data->x;
	new_y = data->y;
	if (x != 0)
	{
		new_x += data->dir_x * x * MOVE_SPEED;
		new_y += data->dir_y * x * MOVE_SPEED;
	}
	if (y != 0)
	{
		new_x += data->plane_x * y * MOVE_SPEED;
		new_y += data->plane_y * y * MOVE_SPEED;
	}
	if (data->parse->map[(int)(new_y) / (int)(tile_size(data))][(int)(data->x)
		/ (int)(tile_size(data))] != '1')
		data->y = new_y;
	if (data->parse->map[(int)(data->y) / (int)(tile_size(data))][(int)(new_x)
		/ (int)(tile_size(data))] != '1')
		data->x = new_x;
}

void	player_dir(t_data *data, int y, int x)
{
	char	c;
	double	length;

	c = data->parse->map[y][x];
	data->dir_angle = 0;
	if (!c)
		return ;
	if (c == 'N')
		data->dir_angle = 270 * (deg_to_rad());
	if (c == 'E')
		data->dir_angle = 0;
	if (c == 'S')
		data->dir_angle = 90 * (deg_to_rad());
	if (c == 'W')
		data->dir_angle = 180 * (deg_to_rad());
	data->dir_x = data->x * cos(data->dir_angle) - data->dir_y
		* sin(data->dir_angle);
	data->dir_y = data->x * sin(data->dir_angle) + data->dir_y
		* cos(data->dir_angle);
	length = sqrt(data->dir_x * data->dir_x + data->dir_y * data->dir_y);
	if (length > 0.00001)
	{
		data->dir_x /= length;
		data->dir_y /= length;
	}
}

void	ft_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->parse->map[y])
	{
		x = 0;
		while (data->parse->map[y][x])
		{
			if (data->parse->map[y][x] == 'N' || data->parse->map[y][x] == 'S'
				|| data->parse->map[y][x] == 'W'
				|| data->parse->map[y][x] == 'E')
			{
				data->x = x * (tile_size(data)) + ((tile_size(data)) / 2);
				data->y = y * (tile_size(data)) + ((tile_size(data)) / 2);
				player_dir(data, y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	data->dir_y = 0.00001;
	data->dir_x = 0.00001;
	update_player_pos(data);
}

int	loop_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	handle_keypress_loop(data);
	update_player_pos(data);
	ray_casting(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img_struct->img, 0, 0);
	return (0);
}
