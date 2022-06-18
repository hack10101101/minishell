# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 15:19:42 by kdi-noce          #+#    #+#              #
#    Updated: 2022/06/16 20:30:18 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

CFLAGS := ${CFLAGS}

CC	= gcc

INC_FLAGS := -Isrcs/libft/
LIBS := -Lsrcs/libft -lft -lreadline
#UNAME = $(shell uname -s) = connaitre l'os sur lequel on est
UNAME = $(shell uname -s)
#nproc = nombre de coeur disponible
ifeq ($(UNAME), Linux)
	# NPROC := $(shell nproc)
else
	# NPROC := $(shell sysctl -n hw.ncpu)
	INC_FLAGS += -I$(HOME)/.brew/opt/readline/include
    LIBS += -L$(HOME)/.brew/opt/readline/lib
endif

NAME ?= minish

BUILD_DIR ?= ./build
SRC_DIRS ?= ./

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
#$(shell find $(SRC_DIRS) -type d) = trouver les includes dans shell, type d = dossier
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
#INC_FLAGS += $(addprefix -I,$(INC_DIRS)) = ajouter prefix include devant INC_DIRS
INC_FLAGS += $(addprefix -I,$(INC_DIRS))

LIB    := srcs/libft/libft.a

CFLAGS += -Wall -Wextra -g3 #-fsanitize=address
#CFLAGS += -O2 -march=native
#CFLAGS += -g3

#all: make -j : nbr process compilation(plusieur coeur pour compilation) 
all:
	@$(MAKE) -j$(NPROC) $(NAME)
#$(NAME) -> @echo => affiche linking NAME
$(NAME): $(LIB) $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBS) -o $(NAME)
#echo compiling $@ = echo $(BUILD_DIR)
#@mkdir -p $(dir $@) = creer un dossier si existe pas avec $(BUILD_DIR)
$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

$(LIB):
	@$(MAKE) -C srcs/libft
	@echo Libft done
clean:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) -C srcs/libft clean
	@echo Clean done

fclean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME)
	@$(MAKE) -C srcs/libft fclean
	@echo Fclean done
#@$(MAKE) -j$(NPROC) $(NAME) = rappel $(NAME)
re: fclean
	@$(MAKE) -j$(NPROC) $(NAME)

.PHONY: all clean fclean re