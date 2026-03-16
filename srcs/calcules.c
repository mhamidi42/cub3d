/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:50:20 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 21:04:24 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	deg_to_rad(void)
{
	return (M_PI / 180.0);
}

double	tile_size(t_data *data)
{
	return (data->max_x / data->parse->map_width);
}

double	fov_rad(void)
{
	return (60 * (M_PI / 180.0));
}
