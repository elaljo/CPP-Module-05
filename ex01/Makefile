# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 10:43:36 by moelalj           #+#    #+#              #
#    Updated: 2024/11/12 17:13:53 by moelalj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

g++ = c++

RM = rm -rf

SRC = main.cpp\
			Bureaucrat.cpp\
			Form.cpp\

OBJS := $(SRC:.cpp=.o)

all: $(NAME)

%.o:%.cpp Bureaucrat.hpp Form.hpp
	$(g++) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(g++) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all