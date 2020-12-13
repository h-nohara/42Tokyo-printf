CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_plist_util.c ft_tlist_util.c ft_string_util.c ft_detection.c ft_hex.c ft_format_str.c ft_format_int.c ft_format_hex.c
OBJ = ${SRC:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $^

all: ${NAME}

$(NAME): $(OBJ)
	make -C ./libft
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)

re: fclean all
