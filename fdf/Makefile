COMPILE =cc
FILESM = ./main/fdf.c\
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./utils/utils2.c ./utils/readmap.c ./utils/drawmap.c ./utils/colorcode.c ./utils/createmap.c \
		./utils/drawmap_vertical.c ./utils/drawmap_horizontal.c ./utils/putbase.c ./utils/frees.c
MAN = $(FILESM:.c=.o)
LIBFTPRINTFA = libftprintf/libftprintf.a
NAME = fdf.a
LIBM =ar -rcs
FLAGSA =-Wall -Wextra -Werror
FLAGSO = -I minilibx/
FLAGSP = -L minilibx/ -lmlx -lX11 -lXext -lm

all: 
	make -C libftprintf
	make -C minilibx
	ln -f $(LIBFTPRINTFA) $(NAME)
	make $(NAME)
%.o: %.c
	$(COMPILE) $(FLAGSA) $(FLAGSO) -c $< -o $@
	$(LIBM) $(NAME) $@ 
$(NAME): $(MAN)
	$(COMPILE) $(FLAGSA) -L. -l:$(NAME) $(FLAGSP) -o fdf
clean:
	rm -f $(MAN)
	make clean -C libftprintf
fclean:
	make clean
	rm -f $(NAME)
	rm fdf
	make clean -C minilibx
	make fclean -C libftprintf
re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
