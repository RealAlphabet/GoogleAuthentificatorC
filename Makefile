##
## LUMZ APP, 2020
## Makefile
##

SRC         =   $(wildcard src/**.c)
OBJ         =   $(SRC:.c=.o)
PREFIX      =   /usr/local

NAME        = ga
NAME_LIB    = libga.a

CFLAGS      =   -Wall           \
                -W              \
                -I include

all:    $(NAME)

$(NAME):$(OBJ)
	# BIN
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	# LIB
	$(AR) rcs $(NAME_LIB) $(OBJ)

install:
	# BIN
	mkdir -p $(PREFIX)/bin
	cp $(NAME) $(PREFIX)/bin/$(NAME)
	# LIB
	mkdir -p $(PREFIX)/lib
	mkdir -p $(PREFIX)/include
	cp $(NAME_LIB) $(PREFIX)/lib/$(NAME_LIB)
	cp include/totp.h $(PREFIX)/include/ga.h

uninstall:
	# BIN
	rm -f $(PREFIX)/bin/$(NAME)
	# LIB
	rm -f $(PREFIX)/lib/$(NAME_LIB)
	rm -f $(PREFIX)/include/ga.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME_LIB)

re:		fclean all
