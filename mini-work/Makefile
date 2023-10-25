# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adube <adube@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 12:35:03 by adube             #+#    #+#              #
#    Updated: 2023/10/25 09:23:09 by adube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#SETUP
NAME		=	pipex
CC			=	gcc -lreadline
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	header/minishell.h

MPATH_SRCS	=	src/main.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c \
OBJ_M		=	$(MPATH_SRCS:.c=.o)

LIBFT := ./lib/libft
LIBFT_AR := $(LIBFT)/libft.a

LIBRLINE 		= readline-8.2
LIBRLINE_DIR	= ./lib/readline/
RLINE			= $(LIBRLINE_DIR)libreadline.a

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
				@$(CC) $(OBJ_M) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			$(OBJ_B)
				@$(CC) $(OBJ_B) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
