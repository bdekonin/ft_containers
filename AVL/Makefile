# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bdekonin <bdekonin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/28 09:38:22 by bdekonin      #+#    #+#                  #
#    Updated: 2022/05/30 14:57:48 by bdekonin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

FILES =	*.cpp
OBJDIR = obj/

OBJ := $(addprefix $(OBJDIR), $(FILES:%.cpp=%.o))

CC = g++

FLAGS = -g
# FLAGS = -Wall -Wextra -Werror -std=c++98 
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling executable..."
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@echo "Compiling $@"
	@$(CC) -c $(FLAGS) -o $@ $< 

clean:
	@echo "Removing objects..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Deleting executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re