/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:06:08 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/19 15:54:34 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wall_dir(t_raycast *ray_c)
{
	if (ray_c->side == 0)
	{
		if (ray_c->ray_dir_x > 0)
			ray_c->wall_dir = EAST;
		else
			ray_c->wall_dir = WEST;
	}
	else
	{
		if (ray_c->ray_dir_y > 0)
			ray_c->wall_dir = SOUTH;
		else
			ray_c->wall_dir = NORTH;
	}
}

void	wall_hit_dda(t_data *data, t_raycast *ray_c)
{
	while (ray_c->hit == 0)
	{
		if (ray_c->side_dist_x < ray_c->side_dist_y)
		{
			ray_c->side_dist_x += ray_c->delta_dist_x;
			ray_c->map_x += ray_c->step_x;
			ray_c->side = 0;
		}
		else
		{
			ray_c->side_dist_y += ray_c->delta_dist_y;
			ray_c->map_y += ray_c->step_y;
			ray_c->side = 1;
		}
		if (data->parse->map[(int)ray_c->map_y][(int)ray_c->map_x] == '1')
			ray_c->hit = 1;
	}
	if (ray_c->side == 0)
		ray_c->perp_wall_dist = (ray_c->side_dist_x - ray_c->delta_dist_x);
	else
		ray_c->perp_wall_dist = (ray_c->side_dist_y - ray_c->delta_dist_y);
	wall_dir(ray_c);
}

void	calculate_sides(t_raycast *ray_c)
{
	calc_side_x(ray_c);
	calc_side_y(ray_c);
}

void	variable_init(t_raycast *ray_c)
{
	if (ray_c->ray_dir_x == 0)
		ray_c->ray_dir_x = 1e30;
	if (ray_c->ray_dir_y == 0)
		ray_c->ray_dir_y = 1e30;
	ray_c->delta_dist_x = fabs(1 / ray_c->ray_dir_x);
	ray_c->delta_dist_y = fabs(1 / ray_c->ray_dir_y);
	ray_c->map_x = (int)ray_c->pos_x;
	ray_c->map_y = (int)ray_c->pos_y;
}

void	ray_casting(t_data *data)
{
	t_raycast	*ray_c;

	if (data->ray_c)
		free(data->ray_c);
	ray_c = (t_raycast *)malloc(sizeof(t_raycast));
	if (!ray_c)
		close_game(data, MALLOC_FAIL);
	ft_memset(ray_c, 0, sizeof(t_raycast));
	data->ray_c = ray_c;
	data->plane_x = -data->dir_y * tan((fov_rad()) / 2);
	data->plane_y = data->dir_x * tan((fov_rad()) / 2);
	while (data->ray_c->x_index < (data->max_x))
	{
		data->ray_c = ray_c;
		ray_c->pos_x = data->x / (tile_size(data));
		ray_c->pos_y = data->y / (tile_size(data));
		ray_c->hit = 0;
		ray_c->camera_x = 2 * data->ray_c->x_index
			/ ((double)(data->max_x) - 1.0) - 1;
		ray_c->ray_dir_x = data->dir_x + data->plane_x * ray_c->camera_x;
		ray_c->ray_dir_y = data->dir_y + data->plane_y * ray_c->camera_x;
		process_raycasting(data, ray_c);
		data->ray_c->x_index++;
	}
}
