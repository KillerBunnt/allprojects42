COMPILE =cc
FILESM =ft_printf.c print_p.c print_u.c print_x.c
MAN = $(FILESM:.c=.o)
LIBFTA = libft/libft.a
NAME =libftprintf.a
LIBM =ar -rcs
FLAGS =-c -Wall -Wextra -Werror

all: 
	make -C libft
	ln -f $(LIBFTA) $(NAME)
	make $(NAME)
%.o: %.c
	$(COMPILE) $(FLAGS) -c $< -o $@
$(NAME): $(MAN)
	$(LIBM) $(NAME) $(MAN)
clean:
	rm -f $(MAN)
	make clean -C libft
fclean:
	make clean
	rm -f $(NAME)
	make fclean -C libft
re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
