LIB = libft/{ft_atoi,ft_bzero,ft_calloc,ft_isalnum,ft_isalpha,ft_isascii,ft_isdigit,ft_isprint,ft_itoa,ft_memccpy,ft_memchr,ft_memcmp,ft_memcpy,ft_memmove,ft_memset,ft_putchar_fd,ft_putendl_fd,ft_putnbr_fd,ft_putstr_fd,ft_strchr,ft_strlcat,ft_strlcpy,ft_strlen,ft_strmapi,ft_strncmp,ft_strnstr,ft_strrchr,ft_strtrim,ft_tolower,ft_toupper}.c
SRC = main.c init.c operations.c operations_two.c stacks.c stacks_two.c utils.c ft_my_atoi.c

all: push_swap

push_swap:
	@#@$(CC) $(SRC) $(GN) $(LIB) -g -o push_swap -Wall -Wextra -Werror -Werror
	@$(CC) $(SRC) $(GN) $(LIB) -g -o push_swap -fsanitize=address
clean :
	@rm -rf push_swap.o
fclean : clean
		@rm -rf ./push_swap push_swap.dSYM
re : fclean all

.PHONY : all clean fclean re $(NAME)