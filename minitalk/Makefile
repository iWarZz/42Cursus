# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:16:00 by ssalor            #+#    #+#              #
#    Updated: 2023/03/21 10:58:52 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
## ARGUMENTS

NAME = minitalk

MINITALK_SRC = server client

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@cd libft && $(MAKE)
	@gcc $(CFLAGS) server.c libft/libft.a -o server
	@gcc $(CFLAGS) client.c libft/libft.a -o client

clean:
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(MINITALK_SRC)
	@rm -f libft/libft.a

re: fclean all

.PHONY : all clean fclean re