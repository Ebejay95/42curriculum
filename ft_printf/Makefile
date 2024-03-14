# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 11:02:58 by jeberle           #+#    #+#              #
#    Updated: 2024/03/14 11:08:15 by jeberle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CODEDIRS=.
CC=cc ft_printf.c
CFLAGS= -Wall -Wextra -Werror
DEPFLAGS= -MP -MD
CFILES=
BONUSFILES=
OBJECTS=$(CFILES:.c=.o)
BONUSOBJECTS=$(BONUSFILES:.c=.o)
DEPFILES=ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

bonus: $(BONUSOBJECTS)
	ar crs $(NAME) $(BONUSOBJECTS)

clean:
	rm -rf $(OBJECTS) $(BONUSOBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all