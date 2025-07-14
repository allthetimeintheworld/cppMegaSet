CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

NAME = abstractDeathOfAnimal

SRC_DIR = src
SRCS = $(SRC_DIR)/Animal.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/Cat.cpp \
		$(SRC_DIR)/WrongAnimal.cpp $(SRC_DIR)/WrongCat.cpp main.cpp $(SRC_DIR)/Brain.cpp

OBJS = $(SRCS:.cpp=.o)
HEADERS = include/Animal.hpp include/Dog.hpp include/Cat.hpp \
			include/WrongAnimal.hpp include/WrongCat.hpp include/Brain.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@


main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re