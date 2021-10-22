# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shavok <shavok@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 19:17:12 by shavok            #+#    #+#              #
#    Updated: 2021/10/22 18:51:23 by shavok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c		ft_to_percent.c		ft_spec.c\
				ft_put_char.c	ft_put_str.c		ft_put_int.c\
				ft_put_hex.c	ft_put_ptr.c		ft_put_unint.c\
				ft_put_prcnt.c

HEADER		=	ft_printf.h
LIBFT_PATH	=	./libft
OBJ			=	$(SRCS:%.c=%.o)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I $(HEADER) 

.PHONY	:	all clean fclean re

all		:	$(NAME)	

$(NAME)	:	$(OBJ)	$(HEADER)
	make re -C $(LIBFT_PATH)
	ar rc $(NAME) $(OBJ) $(LIBFT_PATH)/*.o
	ranlib $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean	:
	@rm -f	$(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean	:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re		:	fclean all
