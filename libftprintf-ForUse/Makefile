COMPILE =cc
NAME =libftprintf.a

all: $(NAME)

$(NAME): libftprintf/*.o
	make -C libftprintf
	cp libftprintf/$(NAME) $(NAME)
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
