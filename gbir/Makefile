#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/15 16:18:42 by gbir              #+#    #+#              #
#    Updated: 2014/02/17 20:58:07 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	42sh
CC		=	cc

S_GE	=	main.c				gnl.c				allfree.c			
S_LX	=	lx_lexer.c			lx_pars.c			lx_pars_gen.c		\
			lx_pa_translate.c	lx_pa_arg.c

SRCS	=	$(S_GE)	$(S_LX)

OBJ		=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra -O3
LIBFLAG	=	-L./libft -lft

all:		$(NAME)

$(NAME):	libft $(OBJ)
			$(CC) $(LIBFLAG) -o $(NAME) $(OBJ)

$(OBJ):		$(SRCS)
			$(CC) -c $(CFLAGS) $(SRCS)

libft:
			make -C libft

clean:
			make -C libft clean
			rm -f $(OBJ)

fclean:		clean
			make -C libft fclean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean libft
