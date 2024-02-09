# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 12:43:01 by imisumi           #+#    #+#              #
#    Updated: 2024/02/08 16:31:05 by imisumi-wsl      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

CC = c++

CFLAGS = -std=c++23
CFLAGS += -Wall -Wextra -Werror -g

SRCDIR		:= src
INCDIR		:= include
OBJDIR		:= .obj

SOURCES		:= $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJECTS		:= $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<
	@echo "Compiled "$<" successfully!"

run: all
	@./$(NAME) ./input "s" "ss"
	
clean:
	@rm -rf $(OBJDIR)
	@echo "Cleanup complete!"

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re run