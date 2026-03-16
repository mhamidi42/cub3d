# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 02:33:28 by nleoni            #+#    #+#              #
#    Updated: 2025/03/18 20:53:55 by nleoni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC					= cc
CFLAGS				= -Wall -Wextra -Werror -g
NAME				= cub3D

INCLUDES			= inc
LIBFT				= ft
LIBFT_DIR			= libft
SRCS_DIR			= srcs
OBJS_DIR			= objs

FILES				= calcules \
					  close_game \
					  close_imgs \
					  main \
					  map \
					  movement \
					  movement_hooks \
					  parsing \
					  parsing_colors \
					  parsing_map \
					  parsing_map2 \
					  parsing2 \
					  parsing_utils \
					  parsing_utils2 \
					  parsing_utils3 \
					  parsing_utils4 \
					  ray_cast \
					  ray_cast_utils \
					  textures \
					  textures_init \

SRCS_FILES			= $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS_FILES			= $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

GPATH = ./mlx
MLX_PATH = $(GPATH)/libmlx_Linux.a
CFLAGS += -I$(GPATH) -I$(LIBFT_DIR) -I $(INCLUDES)
LDFLAGS = -L$(LIBFT_DIR) -l$(LIBFT) -L$(GPATH) -lmlx -lX11 -lXext -lm -lbsd

all: $(NAME)

$(NAME): _mlx _libft $(OBJS_FILES) $(MLX_PATH)
	@$(CC) $(OBJS_FILES) $(CFLAGS) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

_mlx:
	@make -C $(GPATH)

_libft:
	@make -C $(LIBFT_DIR)

clean :
	@make clean -C $(GPATH)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re _mlx _libft
