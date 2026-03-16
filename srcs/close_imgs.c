/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:10:53 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 18:49:42 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	destroy_images(t_data *data)
{
	if (data->img_struct && data->img_struct->img)
		mlx_destroy_image(data->mlx, data->img_struct->img);
	if (!data->textures)
		return ;
	if (data->textures->wall_no)
		mlx_destroy_image(data->mlx, data->textures->wall_no);
	if (data->textures->wall_so)
		mlx_destroy_image(data->mlx, data->textures->wall_so);
	if (data->textures->wall_we)
		mlx_destroy_image(data->mlx, data->textures->wall_we);
	if (data->textures->wall_ea)
		mlx_destroy_image(data->mlx, data->textures->wall_ea);
}

void	free_structs(t_data *data)
{
	if (data->img_struct)
		free(data->img_struct);
	if (data->textures)
		free(data->textures);
	if (data->parse)
		free_parsing(data->parse);
	if (data->ray_c)
		free(data->ray_c);
}
