COMPILE =cc
FILESM = ./server_files/server.c \
		./client_files/client.c
MAN = $(FILESM:.c=.o)
LIBFTPRINTFA = libftprintf/libftprintf.a
NAME = minitalk.a
LIBM =ar -rcs
FLAGS =-Wall -Wextra -Werror

all: 
	make -C libftprintf
	ln -f $(LIBFTPRINTFA) $(NAME)
	make $(NAME)
%.o: %.c
	$(COMPILE) $(FLAGS) -c $< -o $@
	$(LIBM) $(NAME) $@
$(NAME): $(MAN)
	$(COMPILE) $(FLAGS) -o server ./server_files/server.c -L. -l:$(NAME)
	$(COMPILE) $(FLAGS) -o client ./client_files/client.c -L. -l:$(NAME)
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
