COMPILE =cc
FILESM = ./main/fdf.c ./main/fdf1.c\
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./utils/utils2.c ./utils/readmap.c ./utils/drawmap.c ./utils/colorcode.c
MAN = $(FILESM:.c=.o)
LIBFTPRINTFA = libftprintf/libftprintf.a
NAME = fdf.a
LIBM =ar -rcs
FLAGSA =-Wall -Wextra -Werror
FLAGSO = -I minilibx/
FLAGSP = -L minilibx/ -lmlx -lX11 -lXext -lm

all: 
	make -C libftprintf
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
	make fclean -C libftprintf
re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
