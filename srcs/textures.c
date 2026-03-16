/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:00:26 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 18:52:09 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	color_image(t_data *data, int tex_x, int tex_y)
{
	int		color;
	char	*tex_addr;
	int		line_length;
	int		bpp;

	bpp = 0;
	line_length = 0;
	tex_addr = NULL;
	color = 0;
	get_texture_info(data, &tex_addr, &line_length, &bpp);
	color = *(unsigned int *)(tex_addr
			+ (tex_y * line_length + tex_x * (bpp / 8)));
	return (color);
}

void	get_size_of_image(t_data *data)
{
	if (data->ray_c->wall_dir == NORTH)
	{
		data->textures->tex_width = data->textures->no_width;
		data->textures->tex_heigth = data->textures->no_heigth;
	}
	else if (data->ray_c->wall_dir == SOUTH)
	{
		data->textures->tex_width = data->textures->so_width;
		data->textures->tex_heigth = data->textures->so_heigth;
	}
	else if (data->ray_c->wall_dir == WEST)
	{
		data->textures->tex_width = data->textures->we_width;
		data->textures->tex_heigth = data->textures->we_heigth;
	}
	else if (data->ray_c->wall_dir == EAST)
	{
		data->textures->tex_width = data->textures->ea_width;
		data->textures->tex_heigth = data->textures->ea_heigth;
	}
}

void	calc_textures(t_data *data, t_raycast *ray_c)
{
	double	wall_hit;

	get_size_of_image(data);
	data->textures->tex_w = data->textures->tex_width;
	data->textures->tex_h = data->textures->tex_heigth;
	if (ray_c->wall_dir == NORTH || ray_c->wall_dir == SOUTH)
		wall_hit = ray_c->pos_x + ray_c->perp_wall_dist * ray_c->ray_dir_x;
	else
		wall_hit = ray_c->pos_y + ray_c->perp_wall_dist * ray_c->ray_dir_y;
	wall_hit -= floor(wall_hit);
	data->textures->tex_x = (int)(wall_hit * (double)data->textures->tex_w);
	if ((ray_c->wall_dir == NORTH && ray_c->ray_dir_y > 0)
		|| (ray_c->wall_dir == SOUTH && ray_c->ray_dir_y < 0)
		|| (ray_c->wall_dir == EAST && ray_c->ray_dir_x < 0)
		|| (ray_c->wall_dir == WEST && ray_c->ray_dir_x > 0))
			data->textures->tex_x = data->textures->tex_w
			- data->textures->tex_x - 1;
	if (data->textures->tex_x < 0)
		data->textures->tex_x = 0;
	if (data->textures->tex_x >= data->textures->tex_w)
		data->textures->tex_x = data->textures->tex_w - 1;
}

void	get_textures_x(t_data *data, int line_height)
{
	int		i;
	int		color;
	double	step;
	double	tex_pos;

	calc_textures(data, data->ray_c);
	step = (double)data->textures->tex_h / (double)line_height;
	tex_pos = (data->ray_c->draw_start - data->max_y / 2
			+ line_height / 2) * step;
	i = data->ray_c->draw_start;
	while (i <= data->ray_c->draw_end)
	{
		data->textures->tex_y = (int)tex_pos;
		tex_pos += step;
		if (data->textures->tex_y < 0)
			data->textures->tex_y = 0;
		if (data->textures->tex_y >= data->textures->tex_h)
			data->textures->tex_y = data->textures->tex_h - 1;
		color = color_image(data, data->textures->tex_x, data->textures->tex_y);
		vertical_line(data, i, i, color);
		i++;
	}
}

void	f_c_textures(t_data *data, int draw_start, int draw_end)
{
	int	color_floor;
	int	color_cell;

	color_cell = (data->parse->cell[0] << 16)
		| (data->parse->cell[1] << 8) | data->parse->cell[2];
	color_floor = (data->parse->floor[0] << 16)
		| (data->parse->floor[1] << 8) | data->parse->floor[2];
	vertical_line(data, 0, draw_start - 1, color_cell);
	vertical_line(data, draw_end + 1, (data->max_y) - 1, color_floor);
}
