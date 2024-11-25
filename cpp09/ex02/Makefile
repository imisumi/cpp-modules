# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 12:43:01 by imisumi           #+#    #+#              #
#    Updated: 2024/05/31 01:55:20 by imisumi-wsl      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++

CFLAGS = -std=c++20
# CFLAGS += -Wall -Wextra -Werror

ARGS := 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
# ARGS := 11 2 21 0 16 8 6 15 10 3 17 1 18 9 14 19 12 5 4 20 13 7
# ARGS := 2 1 3 4


SRCDIR		:= .
INCDIR		:= .
OBJDIR		:= .obj

SOURCES		:= $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJECTS		:= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<
	@echo "Compiled "$<" successfully!"

run: all
	@./$(NAME) $(ARGS)
	
clean:
	@rm -rf $(OBJDIR)
	@echo "Cleanup complete!"

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re run