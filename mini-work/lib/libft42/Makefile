# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchampag <mchampag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 09:15:46 by adube             #+#    #+#              #
#    Updated: 2024/03/17 21:18:31 by mchampag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c \
				   	ft_isprint.c \
				   	ft_memcmp.c \
				   	ft_strlcat.c \
					ft_strncmp.c \
				   	ft_atoi.c \
				   	ft_isalpha.c \
				   	ft_memcpy.c \
				 	ft_strchr.c \
				  	ft_strlcpy.c \
					ft_strnstr.c \
				   	ft_tolower.c \
				   	ft_bzero.c \
				 	ft_isascii.c \
					ft_memmove.c \
				   	ft_strdup.c \
				  	ft_strlen.c \
				  	ft_strrchr.c \
					ft_toupper.c \
				   	ft_calloc.c \
				  	ft_isdigit.c \
				   	ft_memchr.c \
				  	ft_memset.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putstr_fd.c \
					ft_putnbr_fd.c \
					ft_itoa.c \
					ft_split.c \
					ft_strcpy.c \
					ft_memdel.c \
					ft_strcmp.c \
					ft_strjoin_free.c \
					ft_free_table.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstadd_back.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstsize.c \
					ft_del.c \
					ft_lstremovenode.c \
					ft_strappend.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
