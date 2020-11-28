# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnohara <hnohara@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 01:33:31 by hnohara           #+#    #+#              #
#    Updated: 2020/11/28 20:27:47 by hnohara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS =	ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

B_SRCS = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c
OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar cr $@ ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $^

#${OBJS}: ${SRCS}
#	${CC} ${CFLAGS} ${SRCS} -o $@

clean:
	rm -f ${OBJS}
	rm -f ${B_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
#	rm -f ${OBJS}
#	rm -f ${NAME}
#	make all

bonus: ${B_OBJS}
	ar rc ${NAME} ${B_OBJS}

.PHONY: all re clean fclean bonus
