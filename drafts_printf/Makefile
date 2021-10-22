# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shavok <shavok@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 15:34:47 by shavok            #+#    #+#              #
#    Updated: 2021/10/20 16:11:46 by shavok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	

HEADERS		=	./headers/*.h
OBJ			=	*.o
LIBFT_PATH	=	./libft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -c 

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:
	make re -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(SRCS) -I $(HEADERS)
	ar rc $(NAME) $(OBJ) $(LIBFT_PATH)/*.o
	ranlib $(NAME)

clean	:
	@rm -f	$(OBJ) $(OBJ_B)
	@make clean -C $(LIBFT_PATH)

fclean	:	clean
	@rm -f $(NAME)
	@make clean -C $(LIBFT_PATH)

re		:	fclean all