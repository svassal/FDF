# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svassal <svassal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 17:22:12 by svassal           #+#    #+#              #
#    Updated: 2016/04/07 15:33:19 by svassal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC=ft_abs.c ft_itoa.c ft_memcmp.c ft_putnbr_fd.c ft_striter.c ft_strnstr.c \
ft_atoi.c ft_itoabase.c ft_memcpy.c ft_putstr.c ft_striteri.c ft_strrchr.c \
ft_atoibase.c ft_lstadd.c ft_memdel.c ft_putstr_fd.c ft_strjoin.c ft_strrev.c \
ft_bzero.c ft_lstdel.c ft_memmove.c ft_sqrt.c ft_strlcat.c ft_strsplit.c \
ft_isalnum.c ft_lstdelone.c ft_memset.c ft_strcat.c ft_strlen.c ft_strstr.c \
ft_isalpha.c ft_lstiter.c ft_pow.c ft_strchr.c ft_strmap.c ft_strsub.c \
ft_isascii.c ft_lstmap.c ft_putchar.c ft_strclr.c ft_strmapi.c ft_strtrim.c \
ft_isdigit.c ft_lstnew.c ft_putchar_fd.c ft_strcmp.c ft_strncat.c ft_swap.c \
ft_islower.c ft_lstpushback.c ft_putendl.c ft_strcpy.c ft_strncmp.c \
ft_isprint.c ft_memalloc.c ft_putendl_fd.c ft_strdel.c ft_strncpy.c \
ft_isupper.c ft_memccpy.c ft_strdup.c ft_strnequ.c ft_toupper.c \
ft_iswhitespace.c ft_memchr.c ft_putnbr.c ft_strequ.c ft_strnew.c ft_tolower.c \
ft_putendl_color.c ft_putendl_color_fd.c ft_putnbr_color.c \
ft_putnbr_color_fd.c ft_putstr_color.c ft_putstr_color_fd.c \
ft_putchar_color.c ft_putchar_color_fd.c get_next_line.c ft_ishexa.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

%.o:%.c
	gcc -c -I includes $(FLAG) $^ -o $@
