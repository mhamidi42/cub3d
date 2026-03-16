/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:11:59 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 18:50:42 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_texture_info(t_data *data, char **tex_addr, int *line_l, int *bpp)
{
	if (data->ray_c->wall_dir == NORTH)
	{
		*tex_addr = data->textures->addr_no;
		*line_l = data->textures->line_length_no;
		*bpp = data->textures->bpp_no;
	}
	else if (data->ray_c->wall_dir == SOUTH)
	{
		*tex_addr = data->textures->addr_so;
		*line_l = data->textures->line_length_so;
		*bpp = data->textures->bpp_so;
	}
	else if (data->ray_c->wall_dir == WEST)
	{
		*tex_addr = data->textures->addr_we;
		*line_l = data->textures->line_length_we;
		*bpp = data->textures->bpp_we;
	}
	else if (data->ray_c->wall_dir == EAST)
	{
		*tex_addr = data->textures->addr_ea;
		*line_l = data->textures->line_length_ea;
		*bpp = data->textures->bpp_ea;
	}
}

void	init_textures(t_data *data, t_textures *tex)
{
	tex->wall_no = mlx_xpm_file_to_image(data->mlx, data->parse->path_north,
			&tex->no_width, &tex->no_heigth);
	tex->wall_so = mlx_xpm_file_to_image(data->mlx, data->parse->path_south,
			&tex->so_width, &tex->so_heigth);
	tex->wall_we = mlx_xpm_file_to_image(data->mlx, data->parse->path_west,
			&tex->we_width, &tex->we_heigth);
	tex->wall_ea = mlx_xpm_file_to_image(data->mlx, data->parse->path_east,
			&tex->ea_width, &tex->ea_heigth);
	if (!tex->wall_no || !tex->wall_so
		|| !tex->wall_we || !tex->wall_ea)
		close_game(data, MLX_FT_FAIL);
	tex->addr_no = mlx_get_data_addr(tex->wall_no, &tex->bpp_no,
			&tex->line_length_no, &tex->endian);
	tex->addr_so = mlx_get_data_addr(tex->wall_so, &tex->bpp_so,
			&tex->line_length_so, &tex->endian);
	tex->addr_we = mlx_get_data_addr(tex->wall_we, &tex->bpp_we,
			&tex->line_length_we, &tex->endian);
	tex->addr_ea = mlx_get_data_addr(tex->wall_ea, &tex->bpp_ea,
			&tex->line_length_ea, &tex->endian);
	if (!tex->addr_no || !tex->addr_so
		|| !tex->addr_we || !tex->addr_ea)
		close_game(data, MLX_FT_FAIL);
}

void	load_textures(t_data *data)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		close_game(data, MALLOC_FAIL);
	ft_memset(textures, 0, sizeof(t_textures));
	data->textures = textures;
	init_textures(data, data->textures);
}
