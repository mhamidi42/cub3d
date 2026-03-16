/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:21:54 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 21:07:56 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cub_init(t_data *data)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		close_game(data, MALLOC_FAIL);
	ft_memset(img, 0, sizeof(t_img));
	data->img_struct = img;
	img->img = mlx_new_image(data->mlx, data->max_x, data->max_y);
	if (!img->img)
		close_game(data, MLX_FT_FAIL);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	if (!img->addr)
		close_game(data, MLX_FT_FAIL);
}

void	data_init(t_data *data, t_parsing *parse, int ac, char **av)
{
	if (ac != 2)
		exit(0);
	ft_memset(data, 0, sizeof(t_data));
	data->fd = av[1];
	init_parsing(parse);
	data->parse = parse;
	if (handle_parsing(av[1], parse))
		exit(1);
	map_init(data);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		close_game(data, MLX_FAILED);
	load_textures(data);
	mlx_get_screen_size(data->mlx, &data->max_x, &data->max_y);
	data->win = mlx_new_window(data->mlx, data->max_x, data->max_y, "cub3D");
	if (!data->win)
		close_game(data, MLX_FAILED);
	cub_init(data);
	ft_player(data);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_parsing	parse;

	data_init(&data, &parse, ac, av);
	start_game(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handle_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, handle_key_release, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_hook, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_hook(data.win, 17, 0, hook_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
