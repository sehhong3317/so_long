# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/08 17:15:30 by sehhong           #+#    #+#              #
#    Updated: 2021/09/29 19:58:24 by sehee            ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I./includes

FILES = ft_abs_int ft_itoa ft_memset ft_strlen ft_strchr ft_strrchr \
		 ft_strncmp ft_strdup ft_strjoin ft_itoa ft_putstr_fd \
		 ft_putnbr ft_putstr ft_strncpy ft_putchar

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY : all clean fclean re
