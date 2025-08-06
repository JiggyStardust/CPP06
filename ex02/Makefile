# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 12:42:11 by sniemela          #+#    #+#              #
#    Updated: 2025/08/06 11:33:35 by saaraniemel      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identifier
CPPFLAGS = -Wall -Werror -Wextra -std=c++11
CPP = c++
SOURCES = src/main.cpp \
			src/Base.cpp

OBJDIR = obj
OBJS = $(SOURCES:src/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	@mkdir -p $(OBJDIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re