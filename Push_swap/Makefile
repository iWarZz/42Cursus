# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 09:12:12 by ssalor            #+#    #+#              #
#    Updated: 2023/06/13 13:17:25 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = includes/libftprintf/libft/libft.a

LIBFTPRINTF	= includes/libftprintf/libftprintf.a

SOURCES = $(shell find ./srcs -iname "*.c")

OBJECTS = ${SOURCES:.c=.o}

all : $(LIBFT) $(LIBFTPRINTF) $(NAME)

$(LIBFT):
	@cd includes/libftprintf/libft && $(MAKE)

$(LIBFTPRINTF):
	@cd includes/libftprintf && $(MAKE)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)
	@echo "push_swap compiled"

clean:
	@$(RM) $(OBJECTS)
	@cd includes/libftprintf/libft && $(MAKE) clean
	@cd includes/libftprintf && $(MAKE) clean

fclean: clean
	@$(RM) includes/libftprintf/libft/libft.a
	@$(RM) includes/libftprintf/libftprintf.a
	@$(RM) $(NAME)
	@echo "fclean success"

re: clean all

.PHONY: all clean fclean re
