/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:30:46 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/19 17:11:59 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_game(data, NULL);
	if (keycode == XK_Left)
		data->key_pressed[1] = 1;
	else if (keycode == XK_Right)
		data->key_pressed[2] = 1;
	else if (keycode < 256)
		data->key_pressed[keycode] = 1;
	return (0);
}

int	handle_key_release(int keycode, t_data *data)
{
	if (keycode < 256)
		data->key_pressed[keycode] = 0;
	if (keycode == XK_Left)
		data->key_pressed[1] = 0;
	if (keycode == XK_Right)
		data->key_pressed[2] = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	int		center_x;
	int		delta_x;
	double	rot;
	double	old_var;

	(void)y;
	center_x = data->max_x / 2;
	delta_x = x - center_x;
	if (delta_x != 0)
	{
		rot = -delta_x * MOUSE_SPEED;
		old_var = data->dir_x;
		data->dir_x = data->dir_x * cos(rot) - data->dir_y * sin(rot);
		data->dir_y = old_var * sin(rot) + data->dir_y * cos(rot);
		old_var = data->plane_x;
		data->plane_x = data->plane_x * cos(rot) - data->plane_y * sin(rot);
		data->plane_y = old_var * sin(rot) + data->plane_y * cos(rot);
		mlx_mouse_move(data->mlx, data->win, center_x, data->max_y / 2);
	}
	return (0);
}

int	handle_keypress_loop(t_data *data)
{
	if (data->key_pressed[1])
		rotate_player(data, -ROTATE_SPEED * (deg_to_rad()));
	if (data->key_pressed[2])
		rotate_player(data, ROTATE_SPEED * (deg_to_rad()));
	if (data->key_pressed[KEY_U] || data->key_pressed[XK_w])
		move_player(data, 1, 0);
	if (data->key_pressed[KEY_D] || data->key_pressed[XK_s])
		move_player(data, -1, 0);
	if (data->key_pressed[KEY_L] || data->key_pressed[XK_a])
		move_player(data, 0, -1);
	if (data->key_pressed[KEY_R] || data->key_pressed[XK_d])
		move_player(data, 0, 1);
	return (0);
}
