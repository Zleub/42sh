# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2014/02/03 19:46:49 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= ft_sh3
LIBNAME		= ./src/libsh3.a
LIBFT		= ./src/libft/libft.a
PRINTF		= ./src/ft_printf/libftprintf.a

SRCDIR		= ./src/
HEADDIR		= ./inc/

SRC			=	./src/gnl.c \
				./src/init.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -g3 -O3
LIBFLAG		= -L./src/ -L./src/libft -L./src/ft_printf -lsh3 -lft -lftprintf -ltermcap
HEADFLAG	= -I$(HEADDIR)

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)

all: $(LIBFT) $(PRINTF) $(LIBNAME) $(NAME)

$(NAME): main.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) -o $(NAME) main.c

$(LIBNAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(PRINTF):
	make -C ./src/ft_printf

$(LIBFT):
	make -C ./src/libft

%.o: %.c
	$(CC) $(CCFLAGS) $(HEADFLAG) -o $@ -c $<

clean:
	make -C ./src/ft_printf clean
	make -C ./src/libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./src/ft_printf fclean
	make -C ./src/libft fclean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all
