# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larmelli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 17:03:58 by larmelli          #+#    #+#              #
#    Updated: 2021/02/25 17:04:02 by larmelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${wildcard *.c} 
OBJS = ${SRCS:.c=.o}
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
NAME = 		libftprintf.a
AR = 		ar -rcs
.c.o :
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME): 	${OBJS}
			${AR} $(NAME) $(OBJS)
all : 		$(NAME)
clean :
			rm -f ${OBJS}
fclean : 	clean
			rm -f ${NAME}
re : 		fclean all
.PHONY : 	all clean fclean re	
