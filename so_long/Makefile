# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 14:35:13 by ssalor            #+#    #+#              #
#    Updated: 2023/04/27 14:55:21 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

INCLUDES = -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"

LIBFT = includes/libft/libft.a

MLX42 = MLX42/build/libmlx42.a

SOURCES = $(shell find ./srcs -iname "*.c")

OBJECTS = ${SOURCES:.c=.o}

all : $(MLX42) $(LIBFT) $(NAME)

$(MLX42) :
	@cd MLX42 && cmake -b build && cmake --build build -j4

$(LIBFT) :
	@cd includes/libft && $(MAKE)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) $(INCLUDES) -o $(NAME)

clean :
	@$(RM) $(OBJECTS)
	@cd includes/libft && $(MAKE) clean

fclean : clean
	@$(RM) includes/libft/libft.a
	@$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re

