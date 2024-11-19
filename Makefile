NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = \
	libft/libft/ft_atoi.c \
	libft/libft/ft_bzero.c \
	libft/libft/ft_calloc.c \
	libft/libft/ft_isalnum.c \
	libft/libft/ft_isalpha.c \
	libft/libft/ft_isascii.c \
	libft/libft/ft_isdigit.c \
	libft/libft/ft_isprint.c \
	libft/libft/ft_itoa.c \
	libft/libft/ft_memchr.c \
	libft/libft/ft_memcmp.c \
	libft/libft/ft_memcpy.c \
	libft/libft/ft_memmove.c \
	libft/libft/ft_memset.c \
	libft/libft/ft_putchar_fd.c \
	libft/libft/ft_putendl_fd.c \
	libft/libft/ft_putnbr_fd.c \
	libft/libft/ft_putstr_fd.c \
	libft/libft/ft_split.c \
	libft/libft/ft_strchr.c \
	libft/libft/ft_strdup.c \
	libft/libft/ft_striteri.c \
	libft/libft/ft_strjoin.c \
	libft/libft/ft_strlcat.c \
	libft/libft/ft_strlcpy.c \
	libft/libft/ft_strlen.c \
	libft/libft/ft_strmapi.c \
	libft/libft/ft_strncmp.c \
	libft/libft/ft_strnstr.c \
	libft/libft/ft_strrchr.c \
	libft/libft/ft_strtrim.c \
	libft/libft/ft_substr.c \
	libft/libft/ft_tolower.c \
	libft/libft/ft_toupper.c \
	libft/printf/ft_printf.c \
	libft/printf/printf_char.c \
	libft/printf/printf_digit.c \
	libft/printf/printf_hex.c \
	libft/printf/printf_ptr.c \
	libft/printf/printf_string.c \
	libft/printf/printf_udigit.c \
	libft/gnl/get_next_line.c \
	libft/gnl/get_next_line_utils.c \
	libft/libft/ft_lstnew_bonus.c \
	libft/libft/ft_lstadd_front_bonus.c \
	libft/libft/ft_lstsize_bonus.c \
	libft/libft/ft_lstlast_bonus.c \
	libft/libft/ft_lstadd_back_bonus.c \
	libft/libft/ft_lstdelone_bonus.c \
	libft/libft/ft_lstclear_bonus.c \
	libft/libft/ft_lstiter_bonus.c \
	libft/libft/ft_lstmap_bonus.c

AR = ar rcs

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 
fclean: clean
	$(RM) $(NAME)

re: fclean all

