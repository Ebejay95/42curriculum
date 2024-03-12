NAME=libft.a
CODEDIRS=. ./libft/
CC=cc
CFLAGS= -Wall -Wextra -Werror
DEPFLAGS= -MP -MD
CFILES= ft_bzero.c ft_atoi.c ft_itoa.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strnstr.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c
OBJECTS=$(CFILES:.c=.o)
DEPFILES=libft.h

all: $(NAME)

$(NAME): $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all