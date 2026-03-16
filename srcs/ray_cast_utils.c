/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:24:36 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 20:56:25 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	vertical_line(t_data *data, int start, int end, int color)
{
	int		y;
	char	*pos;

	y = start;
	if (start < 0)
		y = 0;
	if (end >= data->max_y)
		end = data->max_y - 1;
	while (y <= end)
	{
		pos = data->img_struct->addr + (y * data->img_struct->line_length
				+ data->ray_c->x_index * (data->img_struct->bpp / 8));
		*(unsigned int *)pos = color;
		y++;
	}
}

void	fill_map(t_data *data, t_raycast *ray_c)
{
	int	line_height;

	if (ray_c->perp_wall_dist == 0)
		ray_c->perp_wall_dist = 0.0001;
	line_height = (int)((data->max_y) / ray_c->perp_wall_dist + 1);
	ray_c->draw_start = -line_height / 2 + (data->max_y) / 2;
	if (ray_c->draw_start < 0)
		ray_c->draw_start = 0;
	ray_c->draw_end = line_height / 2 + (data->max_y) / 2;
	if (ray_c->draw_end >= (data->max_y))
		ray_c->draw_end = (data->max_y) - 1;
	if (ray_c->draw_start > ray_c->draw_end)
		return ;
	data->ray_c = ray_c;
	get_textures_x(data, line_height);
	f_c_textures(data, ray_c->draw_start, ray_c->draw_end);
}

void	calc_side_x(t_raycast *ray_c)
{
	if (ray_c->ray_dir_x < 0)
	{
		ray_c->step_x = -1;
		ray_c->side_dist_x = (ray_c->pos_x - ray_c->map_x)
			* ray_c->delta_dist_x;
	}
	else
	{
		ray_c->step_x = 1;
		ray_c->side_dist_x = (ray_c->map_x + 1.0 - ray_c->pos_x)
			* ray_c->delta_dist_x;
	}
}

void	calc_side_y(t_raycast *ray_c)
{
	if (ray_c->ray_dir_y < 0)
	{
		ray_c->step_y = -1;
		ray_c->side_dist_y = (ray_c->pos_y - ray_c->map_y)
			* ray_c->delta_dist_y;
	}
	else
	{
		ray_c->step_y = 1;
		ray_c->side_dist_y = (ray_c->map_y + 1.0 - ray_c->pos_y)
			* ray_c->delta_dist_y;
	}
}

void	update_player_pos(t_data *data)
{
	int	x_pos;
	int	y_pos;

	x_pos = (int)data->x / (tile_size(data));
	y_pos = (int)data->y / (tile_size(data));
	if (x_pos < 0 || y_pos < 0 || x_pos >= data->parse->map_width
		|| y_pos >= data->parse->map_height)
		return ;
}
