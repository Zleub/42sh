#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/15 16:18:42 by gbir              #+#    #+#              #
#    Updated: 2014/02/13 00:15:33 by gbir             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	42sh
CC		=	gcc
SRCS	=	main.c

OBJ		=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra -O3

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

$(OBJ):		$(SRCS)
			$(CC) -c $(CFLAGS) $(SRCS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
