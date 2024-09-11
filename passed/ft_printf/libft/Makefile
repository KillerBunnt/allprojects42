COMPILE =cc
FILESM =ft_a*.c ft_b*.c ft_c*.c\
	   ft_i*.c ft_m*.c ft_p*.c\
	   ft_s*.c\
	   ft_t*.c
MAN =$(FILESM:.c=.o)
NAME =libft.a
LIBM =ar -rcs
FLAGS =-c -Wall -Wextra -Werror
$(NAME):
	$(COMPILE) $(FLAGS) $(FILESM)
	$(LIBM) $(NAME) $(MAN)
all:
	make $(NAME)
clean:
	rm -f $(MAN)
fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean 
	make all

.PHONY: all, clean, fclean, re
