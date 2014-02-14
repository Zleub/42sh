#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/15 16:18:42 by gbir              #+#    #+#              #
#    Updated: 2014/02/13 21:36:15 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	sh
CC		=	cc
SRCS	=	main.c		gnl.c		allfree.c

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
