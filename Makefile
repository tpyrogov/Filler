CFLAGS		=	-Wall -Wextra -Werror
SRC			=	./free.c \
                ./init.c \
                ./main.c \
                ./map.c
INCL		=	./filler.h
INCL_LIB	=	./libft/includes/libft.h
OBJ			=	$(SRC:.c=.o)
NAME		=	tpyrogov.filler

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	gcc $(CFLGS) -o $@ $(OBJ) -L ./libft -lft

$(OBJ):%.o: %.c
	gcc ${CFLAGS} -I=${INCL} -c $< -o $@

clean:
	rm -f *.o
	rm -f ./libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all