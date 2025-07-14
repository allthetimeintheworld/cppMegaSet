CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = src/Main.cpp src/PhoneBook.cpp src/Contact.cpp
OBJ = $(SRC:.cpp=.o)
NAME = MyAwesomePhoneBook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re