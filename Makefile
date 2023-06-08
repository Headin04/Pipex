# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:42:57 by ode-cleb          #+#    #+#              #
#    Updated: 2023/05/30 16:36:17 by ode-cleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

		#COMMAND#

CC				= cc
MKDIR			= mkdir -p
RM				= rm -rf

		#SOURCES#

C_DIR			= src
C_FILES			= main.c\
					utils.c\
					open_close.c\
					pipe_fork.c\
					behavior.c\
					lst.c\
#C_FILES_BONUS	=

SRCS			= $(patsubst %, $(C_DIR)/%, $(C_FILES))
#SRCS_BONUS		= $(patsubst %, $(C_DIR)/%, $(C_FILES_BONUS))

		#OBJECTS#

O_DIR			= objs
O_FILES			= $(C_FILES:.c=.o)
#O_FILES_BONUS	= $(C_FILES_BONUS:.c=.o)
OBJS			= $(patsubst %, $(O_DIR)/%, $(O_FILES))
#OBJS_BONUS		= $(patsubst %, $(O_DIR)/%, $(O_FILES_BONUS))

		#FLAGS#

FLAGS			= -Wall -Wextra -Werror -g3 -MMD

ifeq ($(debug), true)
	FLAGS += -fsanitize=address,undefined -g3
endif

		#INCLUDES#

INCLUDES		= -I ./Ft_printf -I ./include
LIBFTPRINTF			= ./Ft_printf/libftprintf.a

		#RULES#

all: ${NAME}

$(O_DIR):
				$(MKDIR) $(O_DIR)

$(O_DIR)/%.o: $(C_DIR)/%.c
				$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFTPRINTF):
				make -C ./Ft_printf all

$(NAME): $(O_DIR) $(OBJS) $(LIBFTPRINTF)
				$(CC) $(OBJS) $(FLAGS) $(LIBFTPRINTF) -o $@

#bonus: $(O_DIR) $(OBJS_BONUS) $(LIBFTPRINTF) $(MLX)
#				$(CC) $(OBJS_BONUS) $(FLAGS) $(MFLAGS) $(LIBFTPRINTF) $(MLX) -o $@

clean :
				make -C ./Ft_printf clean
				$(RM) $(O_DIR)

fclean :
				$(RM) $(O_DIR)
				make -C ./Ft_printf fclean
				$(RM) $(NAME)
#				$(RM) bonus

re : fclean all

.PHONY: all clean fclean re 
