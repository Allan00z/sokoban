##
## EPITECH PROJECT, 2022
## Sokoban
## File description:
## Makefile
##

SRC	=	src/arg_options.c	\
		src/sokoban_main.c	\
		src/game_manager.c	\
		src/pos_object.c	\
		src/case_gest.c	\
		src/verify.c	\
		lib/my_strcmp.c		\
		lib/my_strlen.c		\
		lib/my_text_map_len.c	\
		lib/my_strcpy_line.c	\
		lib/my_malloc_str.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses

clean:
		rm $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all