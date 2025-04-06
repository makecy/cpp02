GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = fixedPointNumber

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Fixed.cpp \
		
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Sucessfully compiled $(NAME) $(RESET)"
	
%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)Cleaned Objects$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Cleaned $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re