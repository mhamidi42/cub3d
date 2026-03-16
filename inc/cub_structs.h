/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:21:59 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/18 21:07:33 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_H
# define CUB_STRUCTS_H

typedef struct s_parsing
{
	int		map_started;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	char	player_char;
	int		floor[3];
	int		cell[3];
	char	**map;
	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
}	t_parsing;

typedef struct s_textures
{
	int		no_width;
	int		no_heigth;
	int		so_width;
	int		so_heigth;
	int		we_width;
	int		we_heigth;
	int		ea_width;
	int		ea_heigth;
	void	*wall_no;
	void	*wall_so;
	void	*wall_we;
	void	*wall_ea;
	char	*addr_no;
	char	*addr_so;
	char	*addr_we;
	char	*addr_ea;
	int		bpp;
	int		line_length;
	int		endian;
	int		bpp_no;
	int		line_length_no;
	int		bpp_so;
	int		line_length_so;
	int		bpp_we;
	int		line_length_we;
	int		bpp_ea;
	int		line_length_ea;
	int		tex_width;
	int		tex_heigth;
	int		tex_x;
	int		tex_y;
	int		tex_w;
	int		tex_h;
}	t_textures;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_raycast
{
	int		hit;
	int		side;
	int		wall_dir;
	int		x_index;
	double	pos_x;
	double	pos_y;
	double	step_x;
	double	step_y;
	double	map_x;
	double	map_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	draw_start;
	double	draw_end;
}	t_raycast;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*fd;
	int			max_x;
	int			max_y;
	int			move;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			last_mouse_x;
	int			key_pressed[256];
	double		x;
	double		y;
	double		x_pos;
	double		y_pos;
	double		dir_angle;
	double		dir_x;
	double		dir_y;
	double		move_x;
	double		move_y;
	double		plane_y;
	double		plane_x;
	double		camera_x;
	t_raycast	*ray_c;
	t_img		*img_struct;
	t_parsing	*parse;
	t_textures	*textures;
}	t_data;

#endif
