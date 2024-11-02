NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

SRC =  checker_bonus.c tools_bonus.c sorting_bonus.c sort_chucnk_bonus.c list_bonus.c \
	   checks_bonus.c action_b_bonus.c action_a_bonus.c utils_bonus.c free_bonus.c \
	   get_next_line_bonus.c get_next_line_utils_bonus.c extra_moves_bonus.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re