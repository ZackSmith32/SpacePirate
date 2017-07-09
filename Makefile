# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 15:22:15 by zsmith            #+#    #+#              #
#    Updated: 2017/07/09 10:40:22 by zsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bullet

OBJECTS		=	main.o 			\
				Drawable.o		\
				Bullet.o		\
				Player.o		\
				Enemy.o			\

HEADERS		=	.

CLANG		=	clang++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CLANG) $(CXXFLAGS) $(OBJECTS) -o $@ -lncurses -lmenu

%.o:%.cpp
	$(CLANG) $(CXXFLAGS) $^ -c -o $@ -I $(HEADERS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all