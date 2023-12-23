NAME		= push_swap
CFLAGS		= -c -Wall -Werror -Wextra
LIBFT = ./libft
LIBFTA = ./libft/libft.a
SRC			=  src/utils.c src/rules1.c src/rules2.c src/rules3.c src/sort_list.c src/sort_list2.c src/ft_check.c src/ft_init_stacks.c src/ft_error.c \

OBJ			= $(SRC:.c=.o)

all:  $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cc src/main.c $(OBJ) $(LIBFTA) -o $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re