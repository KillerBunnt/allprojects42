COMPILE =cc
FILESM =./*.c
MAN =$(FILESM:.c=.o)
NAME =libftprintf.a
LIBM =ar -rcs
FLAGS =-c -Wall -Wextra -Werror
$(NAME):
	make -C libft
	cp libft/libft.a $(NAME)
	$(COMPILE) $(FLAGS) $(FILESM)
	$(LIBM) $(NAME) $(MAN)
all:
	make $(NAME)
clean:
	rm -f $(MAN)
	make clean -C libft
fclean:
	make clean
	rm -f $(NAME)
	make fclean -C libft
re:
	make fclean 
	make fclean -C libft
	make all

.PHONY: all, clean, fclean, re
