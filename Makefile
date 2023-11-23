# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benny <benny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:44:56 by benny             #+#    #+#              #
#    Updated: 2023/11/20 17:10:56 by benny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	libft/ft_putchar_fd.c \
		libft/ft_strlen.c \
		libft/ft_putstr_fd.c \
		libft/ft_calloc.c \
		libft/ft_bzero.c \
		ft_printf.c \
		put_pointer_addr.c \
		putnbr_base.c \

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f 

CFLAGS = -Wall -Wextra -Werror

all: ${NAME} 

$(NAME): ${OBJS}
		@ar rcs ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re