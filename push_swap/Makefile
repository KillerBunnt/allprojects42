COMPILE =cc
FILESM = ./algorythms/algo1_1.c ./algorythms/algo1_2.c ./algorythms/algo1_help1.c ./algorythms/algo1_help2.c\
			 ./main/frees.c ./main/push_swap.c ./rules/rules1.c\
			./rules/rules2.c ./utils/util1.c ./utils/util2.c ./utils/util3.c
MAN = $(FILESM:.c=.o)
LIBFTPRINTFA = libftprintf/libftprintf.a
NAME = push_swap.a
LIBM =ar -rcs
FLAGS =-Wall -Wextra -Werror -g

all: 
	make -C libftprintf
	ln -f $(LIBFTPRINTFA) $(NAME)
	make $(NAME)
%.o: %.c
	$(COMPILE) $(FLAGS) -c $< -o $@
	$(LIBM) $(NAME) $@
$(NAME): $(MAN)
	$(COMPILE) $(FLAGS) -o push_swap ./main/push_swap.c -L. -l:$(NAME)
clean:
	rm -f $(MAN)
	make clean -C libftprintf
fclean:
	make clean
	rm -f $(NAME)
	rm -f push_swap
	make fclean -C libftprintf
re:
	make fclean
	make all

.PHONY: all, clean, fclean, re
