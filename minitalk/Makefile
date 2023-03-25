# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:16:00 by ssalor            #+#    #+#              #
#    Updated: 2023/03/24 11:30:24 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
## ARGUMENTS

NAME = minitalk

MINITALK_SRC = server client

CFLAGS	= -Wall -Werror -Wextra

RED			= $'\x1b[31m
GREEN		= $'\x1b[32m
YELLOW		= $'\x1b[33m
RESET		= $'\x1b[0m
_SUCCESS	= [$(GREEN)SUCCESS$(RESET)]
_INFO		= [$(YELLOW)INFO$(RESET)]

all: $(NAME)

$(NAME):
	@cd libft && $(MAKE)
	@gcc $(CFLAGS) server.c libft/libft.a -o server
	@gcc $(CFLAGS) client.c libft/libft.a -o client
	@echo "$(_SUCCESS)Server and client are ready."

clean:
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(MINITALK_SRC)
	@rm -f libft/libft.a
	@echo "$(_INFO)$(RED)Server and client removed."

re: fclean all

.PHONY : all clean fclean re