# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 14:33:03 by kfortin           #+#    #+#              #
#    Updated: 2023/08/18 12:51:14 by kfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

MLX = MLX42/build/libmlx42.a
GIT_MLX = git@github.com:codam-coding-college/MLX42.git

###############################################################################
#							    SYSTEM VARIABLES       					  	  #
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -r

###############################################################################
#							 		FILES								  	  #
###############################################################################

SRCS = 	main.c keyhooks.c ft_utilis.c ft_color.c ft_check_ext.c\
		includes/get_next_line.c includes/get_next_line_utilis.c\

OBJS = $(SRCS:.c=.o)

###############################################################################
#							 		RECIPES								  	  #
###############################################################################

all : install $(NAME)

$(NAME) : $(MLX) $(OBJS)
	$(CC) $(OBJS) $(MLX) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib" -o $(NAME) $(MLX)

install :

$(MLX) :
			brew update --quiet
			if brew list cmake &> /dev/null; then \
			echo "Process 1 : cmake"; \
	else \
			brew install cmake &> /dev/null; \
	fi 
			if brew list glfw &> /dev/null; then \
			echo "Process 2 : brew"; \
	else \
			brew install glfw &> /dev/null; \
	fi
			git clone $(GIT_MLX) &> /dev/null
			cd MLX42/ && cmake -B build &> /dev/null
			cd MLX42/ && cmake --build build -j4 &> /dev/null

$(OBJS): %.o:%.c
			$(CC) $(CFLAGS) -o3 -c $< -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all