RED=\033[0;31m
GREEN=\033[0;32m
BLACK=\033[0;30m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
NC=\033[0m
NAME=bin
CC=cc
CFLAGS=-Wall -Wextra -Werror
DEPFLAGS=-MP -MD
LIBDIR = ./libft
LIBS = -L $(LIBDIR) -lft
CODEDIRS=.
CFILES=ft_printf.c
# BONUSFILES=
OBJECTS=$(CFILES:.c=.o)
BONUSOBJECTS=$(BONUSFILES:.c=.o)
DEPS=$(CFILES:.c=.d)
.PHONY: all clean fclean re bonus
all: libft $(NAME)
$(NAME): $(OBJECTS)
	@echo "${YELLOW}############################${NC}"
	@echo "${MAGENTA}FT_PRINTF${NC}"
	@echo "${YELLOW}############################${NC}"
	$(MAKE) -C $(LIBDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)
	@echo "${GREEN}SUCCESS: project compiled ${NC}"
%.o:%.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<
	@echo "${GREEN}SUCCESS: objects compiled ${NC}"
bonus: $(BONUSOBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUSOBJECTS) $(LIBS)
	@echo "${GREEN}SUCCESS: bonus compiled ${NC}"
libft:
	$(MAKE) -C $(LIBDIR)
	@echo "${GREEN}SUCCESS: ${LIBDIR} compiled ${NC}"
clean:
	rm -rf $(OBJECTS) $(BONUSOBJECTS) $(DEPS)
	$(MAKE) -C $(LIBDIR) clean
	@echo "${GREEN}SUCCESS: clean ${NC}"
fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean
	@echo "${GREEN}SUCCESS: fclean ${NC}"
re: fclean all
	@echo "${GREEN}SUCCESS: re ${NC}"
-include $(DEPS)
