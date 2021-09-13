# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 13:55:17 by jberredj          #+#    #+#              #
#    Updated: 2021/08/19 14:05:02 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Minitalk

CC		=	clang
OPTI	=	-O2
CFLAGS	=	-Wall -Werror -Wextra

LIBS	=	libft.a

$(NAME): server client

all : $(NAME)

server: $(LIBS)
	$(CC) $(CFLAGS) server.c libft.a -o server

client: $(LIBS)
	$(CC) $(CFLAGS) client.c libft.a -o client

libft.a:
	make -C libft
	cp libft/libft.a .

clean:
	rm -rf *.o

fclean: clean
	rm -rf server client
	rm -rf *.a

re: fclean all