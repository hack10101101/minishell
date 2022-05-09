# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 15:19:42 by kdi-noce          #+#    #+#              #
#    Updated: 2022/05/09 16:16:53 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT_DIR	= 	./srcs/libft
LIBFT 		= 	$(LIBFT_DIR)/libft.a
PRINTF_DIR	= 	./srcs/printf
PRINTF 		= 	$(PRINTF_DIR)/libftprintf.a
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror -g3 -fsanitize=address
SRC			=	./builtin/builtin_main.c		\
				./builtin/builtin_function.c	\

all:		$(NAME)

$(NAME):	$(LIBFT) $(PRINTF) $(SRC)
		$(MAKE) -C $(LIBFT_DIR)
		$(CC) $(CFLAG) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(PRINTF)):
		make -C $(PRINTF_DIR)

clean:
		make -C clean $(LIBFT_DIR) 

fclean:
		rm -rf $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all