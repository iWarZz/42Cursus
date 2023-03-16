# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:16:00 by ssalor            #+#    #+#              #
#    Updated: 2023/03/16 11:31:27 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
## ARGUMENTS

NAME = minitalk

MINITALK_SRC = server\
				client

# TEXT BACKGROUND COLOR
BG_RED =	$'\x1b[41m'
BG_GREEN =	$'\x1b[42m'

# TEXT COLOR
TC_RED =	$'\x1b[31m'
TC_WHITE =	$'\x1b[37m'

# BOLD
TF_BOLD =	$'\x1b[1m'
TF_END =	$'\x1b[0m'

all: $(NAME)

$(NAME):
	@cd libft && $(MAKE)
	@gcc -Wall -Werror -Wextra server.c libft/libft.a -o server
	@gcc -Wall -Werror -Wextra client.c libft/libft.a -o client

clean:
	cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(MINITALK_SRC)
	@rm -f libft/libft.a

re: fclean all

.PHONY : all clean fclean re