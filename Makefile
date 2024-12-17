all: RaNGer

RaNGer: main.c
	cc -Wall -Wextra -Werror -O main.c -o $@

fclean:
	rm -rf RaNGer

re: fclean all

.PHONY: all fclean re
