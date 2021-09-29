# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 19:01:40 by sehee             #+#    #+#              #
#    Updated: 2021/09/29 19:27:03 by sehee            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_M_DIR = ./srcs/mandatory/
SRCS_M = $(addprefix $(SRCS_M_DIR), \
			check_and_parse_map.c check_and_parse_map2.c \
			exit_utils.c get_next_line.c main.c mlx_hook_functions.c \
			render_total_window.c upload_images.c \
			)
OBJS_M = $(SRCS_M:.c=.o)

SRCS_B_DIR = ./srcs/bonus/
SRCS_B = $(addprefix $(SRCS_B_DIR), \
			check_and_parse_map_bonus.c check_and_parse_map2_bonus.c \
			exit_utils_bonus.c get_next_line_bonus.c main_bonus.c \
			mlx_hook_functions_bonus.c render_total_window_bonus.c \
			render_total_window2_bonus.c upload_images_bonus.c \
			)
OBJS_B = $(SRCS_B:.c=.o)

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./includes

LIBFT_DIR = ./libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)libft.a

LIBMLX_DIR = ./mlx/
LIBMLX_NAME = mlx
LIBMLX = $(LIBMLX_DIR)libmlx.a

ifdef WITH_BONUS
	OBJS = $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L$(LIBFT_DIR) -l$(LIBFT_NAME) \
	-L$(LIBMLX_DIR) -l$(LIBMLX_NAME) -framework OpenGL \
	-framework AppKit -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(LIBMLX):
	make -C $(LIBMLX_DIR) all

bonus:
	make WITH_BONUS=1 all

clean:
	$(RM) $(OBJS_M) $(OBJS_B) 
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean	all

.PHONY: all bonus clean fclean re
