# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 15:19:42 by kdi-noce          #+#    #+#              #
#    Updated: 2022/05/05 18:37:04 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
LIBFT	=	srcs/libft/libft.a
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror -g3 fsanitize=adress
SRC		=	builtin_main.c		\
			builtin_function.c	\

all:		$(NAME)

$(NAME):	$(LIBFT) $(SRC)
			$(CC) $(CFLAG) $(SRC) $(LIBFT) -o $(NAME)

$(LIB):
			make -C libft

clean:
			make -C libft clean

fclean:
			rm -rf $(NAME)
			make -C libft fclean

re:			fclean all