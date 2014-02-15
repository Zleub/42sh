# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adebray <adebray@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 20:25:00 by adebray           #+#    #+#              #
#    Updated: 2014/02/14 23:13:30 by adebray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= nosh
LIBNAME		= ./src/libsh.a
LIBFT		= ./src/libft/libft.a
PRINTF		= ./src/ft_printf/libftprintf.a

SRCDIR		= ./src/
HEADDIR		= ./inc/

SRC			=	./src/gnl.c		./src/ft_putschar.c

OBJ			= $(subst .c,.o,$(SRC))

CC			= gcc
CCFLAGS		= -Werror -Wall -Wextra -Wuninitialized -g3 -O3
LIBFLAG		= -L./src/ -lsh -L./src/libft -lft -L./src/ft_printf -lftprintf
SYSFLAG		= -ltermcap
HEADFLAG	= -I$(HEADDIR)

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)

all: $(LIBFT) $(PRINTF) $(LIBNAME) $(NAME)

$(NAME): main.c
	$(CC) $(CCFLAGS) $(HEADFLAG) $(LIBFLAG) $(SYSFLAG) -o $(NAME) main.c

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
