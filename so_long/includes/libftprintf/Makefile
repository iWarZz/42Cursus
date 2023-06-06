# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 10:46:12 by ssalor            #+#    #+#              #
#    Updated: 2023/06/06 13:49:14 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
## ARGUMENTS

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

###############################################################################
## SOURCES

LIBFT_DIR = libft/

LIBFT_SRCS = ft_atoi\
			ft_bzero\
			ft_calloc\
			ft_isalnum\
			ft_isalpha\
			ft_isascii\
			ft_isdigit\
			ft_isprint\
			ft_itoa\
			ft_memchr\
			ft_memcmp\
			ft_memcpy\
			ft_memmove\
			ft_memset\
			ft_putchar_fd\
			ft_putendl_fd\
			ft_putnbr_fd\
			ft_putstr_fd\
			ft_split\
			ft_strchr\
			ft_strdup\
			ft_striteri\
			ft_strjoin\
			ft_strlcat\
			ft_strlcpy\
			ft_strlen\
			ft_strmapi\
			ft_strncmp\
			ft_strnstr\
			ft_strrchr\
			ft_strtrim\
			ft_substr\
			ft_tolower\
			ft_toupper\
			ft_lstnew\
			ft_lstadd_front\
			ft_lstsize\
			ft_lstlast\
			ft_lstadd_back\
			ft_lstdelone\
			ft_lstclear\
			ft_lstiter\
			ft_lstmap

LIBPTF_DIR = srcs/

LIBPTF_SRCS = ft_printf\
			ft_printf_tools2\
			ft_print_hexa\
			ft_printf_ptr\
			ft_printf_tools\

###############################################################################
## RULES

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(addprefix $(LIBFT_DIR), $(addsuffix .c, $(LIBFT_SRCS)))
	@$(CC) $(CFLAGS) -c $(addprefix $(LIBPTF_DIR), $(addsuffix .c, $(LIBPTF_SRCS)))
	@ar rcs $(NAME) $(addsuffix .o, $(LIBPTF_SRCS)) $(addsuffix .o, $(LIBFT_SRCS))

clean:
	@$(RM) $(addsuffix .o, $(LIBPTF_SRCS))
	@$(RM) $(addsuffix .o, $(LIBFT_SRCS))

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all compile clean fclean re