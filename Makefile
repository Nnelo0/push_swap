NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = SRCS/error_utils.c SRCS/error.c SRCS/main.c \
       SRCS/push.c SRCS/reverse_rotate.c SRCS/rotate.c \
       SRCS/sort_utils.c SRCS/swap.c SRCS/print_list.c \
	   SRCS/sort.c SRCS/sort_utils_utils.c

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -I. -I$(LIBFTDIR) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
