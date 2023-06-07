# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 14:35:13 by ssalor            #+#    #+#              #
#    Updated: 2023/06/07 13:50:37 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

INCLUDES = -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"

LIBFT = includes/libft/libft.a

LIBFTPRINTF = includes/libftprintf/libftprintf.a

MLX42 = MLX42/build/libmlx42.a

SOURCES = $(shell find ./srcs -iname "*.c")

SOURCES_BONUS = $(shell find ./srcs_bonus -iname "*.c")

OBJECTS = ${SOURCES:.c=.o}

OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}

all : $(MLX42) $(LIBFT) $(LIBFTPRINTF) $(NAME)

$(MLX42) :
	@cd MLX42 && cmake -b build && cmake --build build -j4

$(LIBFT) :
	@cd includes/libft && $(MAKE)

$(LIBFTPRINTF) :
	@cd includes/libftprintf && $(MAKE)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LIBFTPRINTF) $(MLX42) $(INCLUDES) -o $(NAME)
	@echo "So_long compiled"

bonus : $(MLX42) $(LIBFT) $(LIBFTPRINTF) $(NAME)_bonus
	@echo "So_long bonus compiled"

$(NAME)_bonus : $(OBJECTS_BONUS)
	@$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(LIBFTPRINTF) $(MLX42) $(INCLUDES) -o $(NAME)_bonus

clean :
	@$(RM) $(OBJECTS) $(OBJECTS_BONUS)
	@cd includes/libft && $(MAKE) clean
	@cd includes/libftprintf && $(MAKE) clean

fclean : clean
	@$(RM) includes/libft/libft.a
	@$(RM) includes/libftprintf/libftprintf.a
	@$(RM) $(NAME) $(NAME)_bonus
	@echo "fclean success"

re : clean all

.PHONY : all bonus clean fclean re

