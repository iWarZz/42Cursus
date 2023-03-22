# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 14:19:51 by ssalor            #+#    #+#              #
#    Updated: 2023/03/15 15:18:18 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
## ARGUMENTS

NAME = libft.a

LIBFT_DIR = base/

PRINTF_DIR = ft_printf/

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

###############################################################################
## SOURCES

LIBFT_SRCS = 	ft_bzero\
				ft_isalnum\
				ft_isalpha\
				ft_isascii\
				ft_isdigit\
				ft_isprint\
				ft_memchr\
				ft_memcpy\
				ft_memmove\
				ft_memset\
				ft_strchr\
				ft_strlcat\
				ft_strlcpy\
				ft_strlen\
				ft_strncmp\
				ft_strrchr\
				ft_tolower\
				ft_toupper\
				ft_memcmp\
				ft_strnstr\
				ft_atoi\
				ft_calloc\
				ft_strdup\
				ft_substr\
				ft_strjoin\
				ft_putchar_fd\
				ft_putendl_fd\
				ft_putstr_fd\
				ft_putnbr_fd\
				ft_strtrim\
				ft_split\
				ft_itoa\
				ft_strmapi\
				ft_striteri\
				ft_lstnew\
				ft_lstadd_front\
				ft_lstsize\
				ft_lstlast\
				ft_lstadd_back\
				ft_lstdelone\
				ft_lstclear\
				ft_lstiter\
				ft_lstmap

PRINTF_SRCS	= 	ft_printf\
				ft_printf_tools2\
				ft_print_hexa\
				ft_printf_ptr\
				ft_printf_tools\

###############################################################################
## RULES
all: $(NAME)

$(NAME):
	@ $(CC) $(CFLAGS) -c $(addprefix $(LIBFT_DIR), $(addsuffix .c, $(LIBFT_SRCS)))
	@ $(CC) $(CFLAGS) -c $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF_SRCS)))
	@ ar rcs $(NAME) $(addsuffix .o, $(PRINTF_SRCS)) $(addsuffix .o, $(LIBFT_SRCS))

clean:
	@$(RM) $(addsuffix .o, $(PRINTF_SRCS))
	@$(RM) $(addsuffix .o, $(LIBFT_SRCS))

fclean: clean
	@$(RM) $(NAME)

re: fclean all

bonus: 

.PHONY : all clean fclean re bonus