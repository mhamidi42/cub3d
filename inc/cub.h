/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamidi <mhamidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:42:04 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/19 17:12:16 by mhamidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define _GNU_SOURCE

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include "../libft/libft.h"
# include "cub_structs.h"

# define KEY_R XK_D
# define KEY_L XK_A
# define KEY_U XK_W
# define KEY_D XK_S
# define MOVE_SPEED 10
# define ROTATE_SPEED 5
# define MOUSE_SPEED 0.0005
# define UPDATE_RATE 5
# define TEXT_WIDTH 80
# define TEXT_HEIGHT 80
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define MALLOC_FAIL "To malloc"
# define MLX_FT_FAIL "In a mlx function"
# define MLX_FAILED "To init mlx"
# define GNL_FAIL "In GNL function"
# define FD_FAIL "To open FD"

/*				calcules					*/
double	fov_rad(void);
double	deg_to_rad(void);
double	tile_size(t_data *data);

/*				close_game					*/
int		hook_close(t_data *data);
int		close_game(t_data *data, char *str);
void	err_message(char *str);
void	free_dbl_array(char **arr);

/*				close_imgs					*/
void	free_structs(t_data *data);
void	destroy_images(t_data *data);

/*				map							*/
int		map_init(t_data *data);

/*				movement					*/
int		loop_hook(void *param);
void	ft_player(t_data *data);
void	player_dir(t_data *data, int y, int x);
void	rotate_player(t_data *data, double angle);
void	move_player(t_data *data, double x, double y);

/*				movement_hooks				*/
int		handle_keypress_loop(t_data *data);
int		mouse_hook(int x, int y, t_data *data);
int		handle_key_press(int keycode, t_data *data);
int		handle_key_release(int keycode, t_data *data);

/*				parsing						*/
int		which_id(char *str);
int		count_elements(char **rgb);
int		check_forbidden_char(char *str);
int		parsing(char *filename, t_parsing *parse);

/*				parsing_colors				*/
int		space_in_str(char *str);
int		check_rgb_format(char **rgb);
int		validate_rgb_values(char **rgb, int *color);
int		parse_color(char *line, int *color, char c);
void	print_map(char **map);

/*				parsing_map					*/
int		allocate_map(t_parsing *parse);
char	*skip_invalid_lines(int fd, int *i, int debut_map);
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
void	fill_map_line(char *line, t_parsing *parse, int j);
void	filling_map(char *filename, int debut_map, t_parsing *parse);

/*				parsing_map2				*/
int		get_map_start_index(char *filename);
char	*skip_empty_lines(int fd, int *i);
void	stock_analyse_map(char *file, t_parsing *parse);
void	map_line(char *line, int *width_max, int *height_max);
void	get_map_size(char *file, int debut_map,
			int *width_max, int *height_max);

/*				parsing_utils				*/
int		is_map_invalid(t_parsing *parse);
int		player_can_move(t_parsing *parse);
int		check_player_pos(t_parsing *parse);
int		count_and_set_player(t_parsing *parse, int i,
			int j, int *player_count);

/*				parsing_utils2				*/
int		str_is_map(char *str);
int		handle_full_line(char *str);
int		handle_empty_line(char *str);
void	init_parsing(t_parsing *parse);
void	free_parsing(t_parsing *parse);

/*				parsing_utils3				*/
int		check_0_adjacent(t_parsing *parse);
int		check_first_last_line(t_parsing *parse);
int		check_first_last_char_from_line(t_parsing *parse);
void	replace_spaces_with_x(char **map);
void	replace_spaces_with_one(char **map);

/*				parsing_utils4				*/
int		validate_map_structure(t_parsing *parse);
int		handle_parsing(char *filename, t_parsing *parse);
int		validate_and_clean_parsing(int parsing_status, t_parsing *parse);
char	*parse_texture_path(char *str, char c, char d);

/*				ray_cast					*/
void	ray_casting(t_data *data);
void	wall_dir(t_raycast *ray_c);
void	variable_init(t_raycast *ray_c);
void	calculate_sides(t_raycast *ray_c);
void	wall_hit_dda(t_data *data, t_raycast *ray_c);
void	process_raycasting(t_data *data, t_raycast *ray_c);

/*				ray_cast_utils				*/
void	calc_side_x(t_raycast *ray_c);
void	calc_side_y(t_raycast *ray_c);
void	update_player_pos(t_data *data);
void	fill_map(t_data *data, t_raycast *ray_c);
void	vertical_line(t_data *data, int start, int end, int color);

/*				textures					*/
int		color_image(t_data *data, int tex_x, int tex_y);
void	get_size_of_image(t_data *data);
void	calc_textures(t_data *data, t_raycast *ray_c);
void	get_textures_x(t_data *data, int line_height);
void	f_c_textures(t_data *data, int draw_start, int draw_end);

/*				textures_init				*/
void	load_textures(t_data *data);
void	init_textures(t_data *data, t_textures *tex);
void	get_texture_info(t_data *data, char **tex_addr, int *line_l, int *bpp);

int		is_map_invalid(t_parsing *parse);
void	update_player_pos(t_data *data);
int		mouse_hook(int x, int y, t_data *data);
int		check_forbidden_char(char *str);

#endif
