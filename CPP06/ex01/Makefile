# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/07/11 10:00:00 by jadyar            #+#    #+#             #
#    Updated: 2025/07/11 10:00:00 by jadyar           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = serializer

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp \
		Serializer.cpp \
		Data.cpp

OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

HEADERS = Serializer.hpp \
			Data.hpp

# Colors for output for a bit of change to feed the boredom
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Running serializer test...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re test
