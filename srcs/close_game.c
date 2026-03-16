/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:49:57 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/19 15:36:23 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	err_message(char *str)
{
	int	i;

	write(2, "Error\n", 6);
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	free_dbl_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int	hook_close(t_data *data)
{
	close_game(data, NULL);
	return (0);
}

int	close_game(t_data *data, char *str)
{
	data->fd = NULL;
	if (data->parse->map)
		free_dbl_array(data->parse->map);
	destroy_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_structs(data);
	if (str)
		err_message(str);
	exit(0);
}
