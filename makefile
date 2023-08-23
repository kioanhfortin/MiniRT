# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 14:33:03 by kfortin           #+#    #+#              #
#    Updated: 2023/08/21 11:17:24 by kfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

MLX = MLX42/build/libmlx42.a
GIT_MLX = https://github.com/codam-coding-college/MLX42.git

###############################################################################
#							    SYSTEM VARIABLES       					  	  #
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -r

###############################################################################
#							 		FILES								  	  #
###############################################################################

SRCS = 	main.c keyhooks.c ft_utilis.c ft_color.c ft_check_ext.c parsing.c parsing2.c\
		ft_check_file.c includes/get_next_line.c includes/get_next_line_utilis.c\
		ft_plan.c\

OBJS = $(SRCS:.c=.o)

LIBDIR = includes/libft/

LIBFT = libft.a

###############################################################################
#							 		RECIPES								  	  #
###############################################################################

all : install $(NAME)

$(NAME) : $(MLX) $(OBJS)
	$(MAKE) -C $(LIBDIR)
	$(CC) $(OBJS) $(LIBDIR)$(LIBFT) $(MLX) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib" -o $(NAME) $(MLX)

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
		$(RM) $(LIBDIR)*.o

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBDIR)$(LIBFT)
	
re : fclean all