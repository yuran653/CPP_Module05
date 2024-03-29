# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 16:40:44 by jgoldste          #+#    #+#              #
#    Updated: 2023/10/04 14:44:47 by jgoldste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		:= bureaucrat

SRCDIR		:= src
OBJDIR		:= object
HDRDIR		:= include
HDR			:= $(wildcard $(HDRDIR)/*.hpp)
INC			:= -I./include

CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -g

SRCS		:= $(wildcard $(SRCDIR)/*.cpp)
OBJS		:= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS		:= $(patsubst %.cpp,$(OBJDIR)/%.d,$(SRCS))

MKDIR		:= mkdir -p
RM			:= rm -rf

# Define color codes for output messages
YELLOW		:= "\033[1;33m"
GREEN		:= "\033[1;32m"
END			:= "\033[0m"

# Declare phony targets
.PHONY: all clean fclean re

# Default target for building the project
all: $(NAME)

# Main target
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN) "\n\tProject is compiled\n" ${END}

# Rule for generating dependency and object files
$(OBJDIR)/%.o: ./%.cpp $(HDR)
	$(MKDIR) $(@D)
	$(CXX) $(CXXFLAGS) $(INC) -g -c -o $@ $< -MD

# Target for cleaning the project
clean:
	$(RM) $(OBJDIR)
	@echo $(YELLOW) "\n\tProject 'clean' status: DONE\n" ${END}

# Target for fully cleaning the project
fclean: clean
	$(RM) $(NAME)
	@echo $(YELLOW) "\n\tProject 'fclean' status: DONE\n" ${END}

# Target for rebuilding the project
re: fclean all
