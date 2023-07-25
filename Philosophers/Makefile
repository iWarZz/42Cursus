# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 14:23:17 by ssalor            #+#    #+#              #
#    Updated: 2023/07/06 14:34:41 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SOURCES = main.c

OBJECTS = ${SOURCES:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "Philo compiled"

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)
	@echo "fclean success"

re: clean all

.PHONY: all clean fclean re