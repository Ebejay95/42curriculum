# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: jeberle <jeberle@student.42.fr>			+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2024/03/14 11:02:58 by jeberle		   #+#	#+#			  #
#	Updated: 2024/03/20 12:05:03 by jeberle		  ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME=libftprintf.a
CC=cc
CFLAGS= -Wall -Wextra -Werror
CFILES= ft_printf.c \
./ft_putnbrr.c \
./ft_putunbrr.c \
./ft_itoa.c \
./ft_calloc.c \
./ft_strlen.c \
./ft_strdup.c \
./ft_memset.c \
./ft_strlcpy.c \
./ft_strbase.c \
./ft_putchar.c \
./ft_putstr.c \
./ft_str_is_unique.c
OBJECTS=$(CFILES:.c=.o)

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rs $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
