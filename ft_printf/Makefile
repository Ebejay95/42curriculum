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

SRC=  ft_printf.c \
./src/ft_putnbrr.c \
./src/ft_putunbrr.c \
./src/ft_itoa.c \
./src/ft_calloc.c \
./src/ft_isprint.c \
./src/ft_strlen.c \
./src/ft_strdup.c \
./src/ft_memset.c \
./src/ft_strlcpy.c \
./src/ft_strbase.c \
./src/ft_putchar.c \
./src/ft_putstr.c \
./src/ft_str_is_unique.c \
./src/smart_prints_1.c \
./src/smart_prints_2.c

OBJS=$(SRC:.c=.o)

RM=	rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
