#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook phoneBook;
	std::string command;

	phoneBook.displayText();

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << "Input terminated." << std::endl;
			break ;
		}
		if (command.empty())
		{
			std::cout << "No command entered. Please try again." << std::endl;
			continue;
		}
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting the PhoneBook. Goodbye!" << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
	return (0);
}