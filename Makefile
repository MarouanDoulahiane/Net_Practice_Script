SRC			=		main.cpp

OBJ			=		$(SRC:.cpp=.o)

HEAD		=		-I./include

CXXFLAGS	=		-Wall -Wextra -Werror

CXX			=		c++

NAME		=		NetPractise_v0.1

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(HEAD)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

push:
	@git add .
	@git commit -m "by auto push script \`cypher\`"
	@git push

.PHONY: all clean fclean re run push