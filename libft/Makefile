# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:33 by jeberle           #+#    #+#              #
#    Updated: 2024/03/21 12:15:18 by jeberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CODEDIRS=.
CC=cc
CFLAGS= -Wall -Wextra -Werror
DEPFLAGS= -MP -MD
CFILES= ft_bzero.c \
ft_atoi.c \
ft_itoa.c \
ft_calloc.c \
ft_strdup.c \
ft_strjoin.c \
ft_strtrim.c \
ft_substr.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_memcpy.c \
ft_memcmp.c \
ft_memmove.c \
ft_memset.c \
ft_strbase.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_str_is_unique.c \
ft_strncmp.c \
ft_strstr.c \
ft_strnstr.c \
ft_split.c \
ft_strrev.c \
ft_putchar.c \
ft_putstr.c \
ft_putendl.c \
ft_putnbr.c \
ft_putnbrr.c \
ft_putunbrr.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_striteri.c \
ft_strreplace.c
BONUSFILES=  ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstmap.c \
ft_lstiter.c
OBJECTS=$(CFILES:.c=.o)
BONUSOBJECTS=$(BONUSFILES:.c=.o)
DEPFILES=libft.h

.PHONY:	all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rs $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(OBJECTS) $(BONUSOBJECTS)
	ar rs $(NAME) $(OBJECTS) $(BONUSOBJECTS)

clean:
	rm -rf $(OBJECTS) $(BONUSOBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all