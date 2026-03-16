# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:18:45 by nleoni            #+#    #+#              #
#    Updated: 2025/01/14 17:46:57 by espinto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#							COLOURS											   #
################################################################################
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
RESET	= \033[0m

ERASE = \033[2K\r

define progress_bar
	@printf "$(ERASE)$(GREEN)[$(1)/$(2)] $(CYAN)Compiling: $(3)...$(RESET)\r"
	sleep 0.02
endef

CURRENT_INDEX := 0

################################################################################
#							FILES											   #
################################################################################
SRCS += ft_isalpha.c
SRCS += ft_isdigit.c
SRCS +=	ft_isalnum.c
SRCS +=	ft_isascii.c
SRCS +=	ft_isprint.c
SRCS +=	ft_strlen.c
SRCS +=	ft_memset.c
SRCS +=	ft_bzero.c
SRCS +=	ft_memcpy.c
SRCS +=	ft_memmove.c
SRCS +=	ft_strlcpy.c
SRCS +=	ft_strlcat.c
SRCS +=	ft_toupper.c
SRCS +=	ft_tolower.c
SRCS +=	ft_strchr.c
SRCS += ft_strrchr.c
SRCS +=	ft_strcmp.c
SRCS +=	ft_strncmp.c
SRCS +=	ft_memchr.c
SRCS +=	ft_memcmp.c
SRCS +=	ft_strnstr.c
SRCS +=	ft_atoi.c
SRCS +=	ft_calloc.c
SRCS += ft_strdup.c
SRCS += ft_arrdup.c

SRCS +=	ft_substr.c
SRCS +=	ft_strjoin.c
SRCS +=	ft_strtrim.c
SRCS +=	ft_split.c
SRCS +=	ft_itoa.c
SRCS +=	ft_strmapi.c
SRCS +=	ft_striteri.c
SRCS +=	ft_putchar_fd.c
SRCS +=	ft_putstr_fd.c
SRCS +=	ft_putendl_fd.c
SRCS +=	ft_putnbr_fd.c

SRCS += get_next_line.c

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

TOTAL_FILES := $(words $(SRCS))

################################################################################
#							DIRECTORIES										   #
################################################################################
OBJDIR		= objects
NAME		= libft.a
INCLUDES	= ./
HEADER		= $(INCLUDES)libft.h

################################################################################
#							COMPILATION										   #
################################################################################
CC			= cc
CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror
CFLAGS		+= -g

################################################################################
#							RULES											   #
################################################################################
all:			$(NAME)
				@printf "\n${GREEN}libft compiled!\n${RESET}"

$(NAME):		$(OBJS)
				@ar rcs $@ $^

$(OBJDIR):
				@mkdir $@

$(OBJDIR)/%.o:	%.c
				$(eval CURRENT_INDEX := $(shell expr $(CURRENT_INDEX) + 1))
				@$(call progress_bar,$(CURRENT_INDEX),$(TOTAL_FILES), $<)
				@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJS):		$(HEADER) | $(OBJDIR)

clean:
				@printf "${YELLOW}Cleaning libft obj...\n${RESET}"
				@$(RM) -r $(OBJDIR)

fclean:			clean
				@$(RM) $(NAME)
				@printf "${YELLOW}libft all cleaned up!\n${RESET}"

re:				fclean all

.PHONY:			all clean fclean re
