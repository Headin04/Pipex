# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 15:56:12 by ode-cleb          #+#    #+#              #
#    Updated: 2022/12/06 13:17:53 by ode-cleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c\
      ft_bzero.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isdigit.c\
      ft_isprint.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_memset.c\
      ft_strchr.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strncmp.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_tolower.c\
      ft_toupper.c\
      ft_calloc.c\
      ft_strjoin.c\
      ft_strtrim.c\
      ft_substr.c\
      ft_strdup.c\
      ft_split.c\
      ft_putchar_fd.c\
      ft_putstr_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
      ft_itoa.c\
      ft_strmapi.c\
      ft_striteri.c\
      ft_lstnew.c\
      ft_lstadd_front.c\
      ft_lstsize.c\
      ft_lstlast.c\
      ft_lstadd_back.c\
      ft_lstdelone.c\
      ft_lstclear.c\
      ft_lstiter.c\
      get_next_line.c\
      ft_strnjoin.c\

OBJS = ${SRCS:c=o}

all: ${NAME}

CC = cc
CFLAGS = -Werror -Wextra -Wall

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

%.o : %.c libft.h
	${CC} -c ${CFLAGS} -o $@ -c $<

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY = clean fclean all re
