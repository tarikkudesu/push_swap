SRC = mand/push_swap.c mand/src/sort_stack.c mand/src/sort_simple.c \
	  mand/operations/swap.c mand/operations/push.c \
	  mand/operations/rotate.c mand/operations/reverse_rotate.c \
	  mand/utils/check_args.c mand/utils/lists.c \
	  mand/libft/libft.c mand/libft/ft_split.c \
	  mand/src/sort_to_b.c mand/src/sort_algo_b.c \
	  mand/src/sort_to_a.c mand/src/sort_algo_a.c

SRC_B = bonus/checker.c bonus/sort_check.c bonus/push.c bonus/swap.c bonus/rotate.c bonus/reverse_rotate.c \
		bonus/libft.c bonus/lists.c bonus/ft_split.c bonus/error.c bonus/get_next_line.c bonus/apply.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap
BONUS = checker

all: ${NAME} clean

bonus: ${BONUS}

%.o:%.c include/push_swap.h bonus/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

${BONUS}: ${OBJ_B}
	${CC} ${CFLAGS} ${OBJ_B} -o ${BONUS}

clean:
	${RM} ${OBJ} ${OBJ_B}

fclean: clean
	${RM} ${NAME} ${BONUS}

re: fclean all
