##
## LUMZ APP, 2020
## Makefile
##

SRC		=	$(wildcard src/**.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	ga

CFLAGS	=	-Wall			\
			-W				\
			-I include		\
			-lm				\
			-g

all:	$(NAME)

$(NAME):$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:		fclean all
