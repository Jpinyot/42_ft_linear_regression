# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 10:22:35 by jpinyot           #+#    #+#              #
#    Updated: 2020/02/11 12:08:42 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_linear_regression

#FLAGS = -Wall -Wextra -Werror
FLAGS =

SRCS_DIR = srcs/

SRCS =	linearRegression.cpp\

OBJ_SRCS = $(patsubst %.cpp, $(SRCS_DIR)%.o, $(SRCS))

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_SRCS)
	@g++ $(FLAGS) -I./srcs/*.h $(OBJ) -o $(NAME)

%.o : %.cpp
	@g++ $(FLAGS) -I./srcs/*.h -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean
	@make

.PHONY: all clean fclean re
