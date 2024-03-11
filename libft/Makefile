NAME=libft.a
CODEDIRS=. ./libft/
CC=cc
CFLAGS= -Wall -Wextra -Werror
DEPFLAGS= -MP -MD
CFILES= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strnstr.c ft_atoi.c
OBJECTS=ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcpy.o ft_memcmp.o ft_memmove.o ft_memset.o ft_strchr.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strrchr.o ft_tolower.o ft_toupper.o ft_strncmp.o ft_strnstr.o ft_atoi.o
DEPFILES=libft.h

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rs $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(NAME) $(OBJECTS)

re:
	$(MAKE) fclean
	$(MAKE) all
