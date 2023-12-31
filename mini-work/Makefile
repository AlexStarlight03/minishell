# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adube <adube@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 12:35:03 by adube             #+#    #+#              #
#    Updated: 2023/11/07 14:07:12 by adube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#SETUP
NAME		=	minishell
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRCS_DIR	=	./src/
SRCS_LST	=	main.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c \
				redirections/pipes.c \
				parsing/parse_builtins.c \
				parsing/parse.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

#FILES AND PATH
HEADER_DIR	=	./include/
HEADER_LST	=	minishell.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LST))

LIBFT_DIR	=	./lib/libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_H		=	$(LIBFT_DIR)libft.h

LIBRLINE 		= readline-8.2
LIBRLINE_DIR	= ./lib/readline/
RLINE			= $(LIBRLINE_DIR)libreadline.a

OBJS_DIR	=	./obj/
OBJS_LST	=	$(patsubst %.c, %.o, $(SRCS_LST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LST))


#COMMANDS
all : dir readline $(NAME)

$(NAME) : 	$(OBJS)
			@make -C $(LIBFT_DIR)
			@$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(RLINE) -lncurses -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADER)
				@$(CC) $(FLAGS) -c $< -o $@

run: 	all
		@./$(NAME)

dir :
		@mkdir -p $(OBJS_DIR) $(OBJS_DIR)parsing $(OBJS_DIR)redirections $(OBJS_DIR)builtins
		@mkdir -p $(LIBRLINE_DIR)

readline :
		@if [ ! -f ./lib/readline/libreadline.a ]; then \
		curl -O https://ftp.gnu.org/gnu/readline/$(LIBRLINE).tar.gz; \
		tar -xf $(LIBRLINE).tar.gz; \
		rm -rf $(LIBRLINE).tar.gz; \
		cd $(LIBRLINE) && bash configure && make; \
		mv ./libreadline.a ../lib/readline; \
		rm -rf ../$(LIBRLINE); \
		echo "----------------------- Readline succesfully configured ✅ -----------------------\n"; \
	fi

clean:
				@make -C $(LIBFT_DIR) clean
				@$(RM) $(OBJS_DIR) $(OBJS_DIR)parsing $(OBJS_DIR)redirections $(OBJS_DIR)builtins
				@echo -e "object deleted!"

fclean:			clean
				@$(RM) $(NAME)
				@make -C $(LIBFT_DIR) fclean
				@$(RM) $(LIBRLINE_DIR)
				@echo -e "everything clean!"

re:				clean all

.PHONY:		all clean fclean bonus re
