NAME=fractol

CC=gcc

CFLAGS= -Wall -Wextra -Werror -g -Ofast

VPATH=functions/fractol

MACROPATH=functions/macrolibx/

LIBFTPATH=functions/libft/

MACRO=$(addprefix $(MACROPATH), libmlx.so)

LIBFT=$(addprefix $(LIBFTPATH), libft.a)

SRC = main.c window_manager.c fractol.c error_manager.c utils.c

OBJDIR=objects/

OBJ=$(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ) $(MACRO) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -lSDL2 -lm

$(OBJDIR)%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR):
	mkdir -p $@

$(MACRO):
	make -C $(MACROPATH) all -j

$(LIBFT):
	make -sC $(LIBFTPATH) all

clean:
	rm -rfd $(OBJDIR)
	make -C $(LIBFTPATH) clean
	make -C $(MACROPATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTPATH) fclean
	make -C $(MACROPATH) fclean

re: fclean all

.PHONY: all clean fclean re
