# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 12:43:01 by imisumi           #+#    #+#              #
#    Updated: 2023/11/28 19:25:38 by ichiro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dreamJob

CC = c++

CFLAGS = -std=c++98
CFLAGS += -Wall -Wextra -Werror

SRCDIR		:= src
INCDIR		:= include
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
	@./$(NAME)
	
clean:
	@rm -rf $(OBJDIR)
	@echo "Cleanup complete!"

fclean: clean
	@rm -rf $(NAME)
	@echo "Executable removed!"

re: fclean all

.PHONY: all clean fclean re run