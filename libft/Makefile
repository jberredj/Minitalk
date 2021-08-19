# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 13:41:15 by jberredj          #+#    #+#              #
#    Updated: 2021/07/21 22:08:28 by jberredj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	libft.a
CC				= 	clang
CFLAGS			= 	-Wall -Werror -Wextra -O3

BUFFER_SIZE		=	32

FT_CTYPE		= 	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c ft_isdigit.c \
					ft_isgraph.c ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
					ft_isxdigit.c

FT_LST			= 	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
					ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c


FT_IO			=	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_base_fd.c ft_put_unbr_fd.c

FT_STRING		=	ft_cw_sep.c ft_split.c ft_strchr.c \
					ft_strrchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
					ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c	ft_bzero.c \
					ft_calloc.c ft_memccpy.c ft_memcpy.c ft_memcmp.c ft_memchr.c ft_memmove.c \
					ft_memset.c

FT_TO			=	ft_atoi.c ft_itoa.c ft_intlen.c ft_intlen_base.c ft_lllen_base.c ft_uitoa.c \
					ft_uintlen.c ft_lltoa.c ft_ulltoa.c ft_ulllen.c ft_lllen.c ft_tolower.c \
					ft_toupper.c ft_ulllen_base.c ft_ulltoa_base.c ft_atof.c ft_atoui32_base.c

FT_UTILS		=	check_base.c ft_swap.c ft_abs.c

GET_NEXT_LINE	=	get_next_line.c get_next_line_utils.c

INCLUDES_PATH	=	includes/

LIBS			=	ft_ctype ft_lst ft_io ft_string ft_to get_next_line

all: $(NAME)
	
$(NAME): $(LIBS) lib 

debug: CFLAGS += -g
debug: all

ft_ctype: objs
	echo "Compiling ft_ctype.h functions"
	$(CC) -I $(INCLUDES_PATH) -c $(addprefix srcs/ft_ctype/, $(FT_CTYPE)) $(CFLAGS)
	mv *.o objs/

ft_lst: ft_string objs
	echo "Compiling ft_lst.h functions"
	$(CC) -I $(INCLUDES_PATH) -c $(addprefix srcs/ft_lst/, $(FT_LST)) $(CFLAGS)
	mv *.o objs/

ft_io: ft_utils ft_string objs
	echo "Compiling ft_io.h functions"
	$(CC) -I $(INCLUDES_PATH) -c $(addprefix srcs/ft_io/, $(FT_IO)) $(CFLAGS)
	mv *.o objs/

ft_string: objs
	echo "Compiling ft_string.h functions"
	$(CC) -I $(INCLUDES_PATH) -c $(addprefix srcs/ft_string/, $(FT_STRING)) $(CFLAGS)
	mv *.o objs/

ft_to: ft_utils ft_ctype ft_string objs
	echo "Compiling ft_to.h functions"
	$(CC) -I $(INCLUDES_PATH) -c $(addprefix srcs/ft_to/, $(FT_TO)) $(CFLAGS)
	mv *.o objs/

ft_utils: objs
	echo "Compiling ft_utils.h functions"
	$(CC) -I $(INCLUDES_PATH) -c $(addprefix srcs/ft_utils/, $(FT_UTILS)) $(CFLAGS)
	mv *.o objs

get_next_line: ft_string
	echo "Compiling get_next_line"
	$(CC) -I $(INCLUDES_PATH) -c $(addprefix srcs/get_next_line/, $(GET_NEXT_LINE)) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -D FD_MAX=`ulimit -Sn`
	mv *.o objs/
so:
	$(CC) -shared -o libft.so objs/*.o

lib: 
	echo "Creating $(NAME)"
	ar cr $(NAME) objs/*.o 

objs:
	mkdir -p objs

clean:
	echo "Cleaning objects in objs and delete objs/"
	rm -f *.o
	rm -rf objs

fclean:
	echo "Deleting $(NAME)"
	rm -f $(NAME)
	make clean

re:
	make fclean
	make all
.SILENT:
