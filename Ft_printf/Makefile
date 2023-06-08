# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 18:06:06 by ode-cleb          #+#    #+#              #
#    Updated: 2023/03/16 17:24:55 by ode-cleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_create_list.c\
       ft_printf_utils.c\
       ft_convert.c\
       ft_printf_utils2.c\
       ft_printf_utils3.c\
	   dpintf.c\

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wextra -Wall -Werror -fPIE

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)/libft.a

all : ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	cp $(LIBFT) $(NAME)
	ar rcs ${NAME} ${OBJS}

${LIBFT}:
	$(MAKE) -sC $(LIBFT_PATH)

%.o : %.c printf_test.h
	${CC} ${CFLAGS} -c $< -o $@ 
	#-I $(LIBFT)#

clean :
	rm -rf *.o
	$(MAKE) -sC $(LIBFT_PATH) clean

fclean : clean
	rm -rf ${NAME}
	$(MAKE) -sC $(LIBFT_PATH) fclean


re : fclean
	$(MAKE)

.PHONY = clean fclean re 

