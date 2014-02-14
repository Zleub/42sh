# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/23 04:54:36 by adebray           #+#    #+#              #
#    Updated: 2014/01/11 06:02:33 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCDIR = ./
HEADDIR = ../../inc

SRC = ft_atoi.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_octal.c \
		ft_hexa.c \
		ft_sheum_hexa.c \
		tools.c

OBJ = $(subst .c,.o,$(SRC))

CC = gcc
CCFLAGS = -Werror -Wall -Wextra -Wuninitialized -g3 -O3
HEADFLAG = -I $(HEADDIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

clean:
	rm -f $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

fclean: clean
	rm -f $(LIBNAME)

re: fclean all
