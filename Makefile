NAME=fractol

CC=gcc

CFLAGS= -Wall -Wextra -Werror -g

VPATH=functions/fractol

LIBPATH=functions/macrolibx/

MACRO=$(addprefix $(LIBPATH), libmlx.so)

SRC = main.c window_manager.c fractol.c

OBJDIR=objects/

OBJ=$(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(MACRO)
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2 -lm

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<


#$@ nom de la regle
#$^ nom de toutes les dependances de la règle
#$< nom de la premiere dependance

$(OBJDIR):
	mkdir -p $@

$(MACRO):
	make -C $(LIBPATH) all -j

clean:
	rm -rfd $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
