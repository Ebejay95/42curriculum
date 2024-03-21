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

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
LIBFT_SRC = ./libft
LIBFT_OBJS = $(LIBFT_SRC:.c=.o)
INCLUDES = -I $(LIBFT_SRC)
all: $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_SRC) bonus
	ar rcs $(NAME) $(OBJS) $(LIBFT_SRC)/*.o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(NAME) main.c -o test
clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_SRC) clean
fclean: clean
	rm -rf $(NAME) test
	$(MAKE) -C $(LIBFT_SRC) fclean
re: fclean all
.PHONY: all clean fclean re