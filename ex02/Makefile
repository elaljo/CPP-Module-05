# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 14:49:38 by moelalj           #+#    #+#              #
#    Updated: 2024/11/15 15:37:16 by moelalj          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

g++ = c++

Target = *_shrubbery

RM = rm -rf

SRC = main.cpp\
			Bureaucrat.cpp\
			AForm.cpp\
			ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp\
			PresidentialPardonForm.cpp\
			

OBJS := $(SRC:.cpp=.o)

all: $(NAME)

%.o:%.cpp Bureaucrat.hpp Form.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	$(g++) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(g++) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(Target)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all