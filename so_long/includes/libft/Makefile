# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 14:19:51 by ssalor            #+#    #+#              #
#    Updated: 2023/04/27 14:55:55 by ssalor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
## ARGUMENTS

NAME = libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

###############################################################################
## SOURCES

SOURCES = ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memchr.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_strchr.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_strrchr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_memcmp.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putstr_fd.c\
			ft_putnbr_fd.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c
OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

###############################################################################
## RULES
all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS):
	@$(CC) $(CFLAGS) -c $(SOURCES)

$(OBJECTS_BONUS):
	@$(CC) $(CFLAGS) -c $(SOURCES_BONUS)
clean:
	@$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	@ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

.PHONY : all clean fclean re bonus