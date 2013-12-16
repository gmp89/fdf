#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 13:47:03 by gpetrov           #+#    #+#              #
#    Updated: 2013/12/16 17:40:23 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fdf
SRCS	= main.c
OBJS	= ${SRCS:.c=.o}
INC		= ./
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) $(SRCS) -o $(NAME) -L /usr/X11/lib -lmlx -lXext -lX11
%.o: %.c
	gcc -c $< -o $@ $(FLAGS) -I$(INC)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
re: fclean all
