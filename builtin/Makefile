# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 15:19:42 by kdi-noce          #+#    #+#              #
#    Updated: 2022/06/07 17:19:37 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
LIBFT		=	srcs/libft/libft.a
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
READLINE	=	-I$(HOME)/.brew/opt/readline/include
READLINE	+=	-L$(HOME)/.brew/opt/readline/lib
SANIT		=	-g3 fsanitize=adress
SRC			=	builtin_main.c											\
				builtin_function.c										\
				annex.c													\
#-I /Users/kdi-noce/.brew/Cellar/readline/8.1.2/include -L /Users/kdi-noce/.brew/Cellar/readline/8.1.2/lib
all:		$(NAME)

$(NAME):	$(LIBFT) $(SRC)
			$(CC) $(CFLAG) $(READLINE) $(SRC) $(LIBFT) -o $(NAME)

$(LIB):
			make -C libft
del:
			rm -rf minishell.dSYM

clean:
			make -C libft clean

fclean:
			rm -rf $(NAME)
			make -C libft fclean

re:			fclean all