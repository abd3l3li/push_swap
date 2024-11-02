NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC =  push_swap.c tools.c sorting.c sort_chucnk.c list.c \
	   checks.c action_b.c action_a.c utils.c free.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

bonus:
	${MAKE} -C checker_bonus

clean_bonus:
	${MAKE} clean -C checker_bonus

fclean_bonus:
	${MAKE} fclean -C checker_bonus

re_bonus:
	${MAKE} re -C checker_bonus

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus re_bonus
.SECONDARY:
