NAME = push_swap
BNAME = checker

CC = CC
CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_push.c ft_error.c pop_and_push.c push_swap.c ft_rotate.c checker_utils.c utils_normi.c ft_rev_rotate.c ft_swap.c parsing.c utils.c sort.c parcours_stack.c utils_sort.c sort_stack.c
BSRC = ft_checker.c checker_utils.c checker_utils1.c ft_error.c\
		ft_push.c pop_and_push.c ft_rotate.c ft_rev_rotate.c ft_swap.c parsing.c \
		utils.c sort.c parcours_stack.c utils_sort.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus:$(BNAME)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(BOBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BNAME)

re: fclean all

.PHONY: all clean fclean re