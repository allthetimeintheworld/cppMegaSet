#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

PhoneBook::PhoneBook() : contactCount(0)
{
	return ;
}

bool PhoneBook::getInput(const std::string &prompt, std::string &input)
{
	std::cout << prompt;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cout << "Input terminated." << std::endl;
		return false;
	}
	if (input.empty())
	{
		std::cout << "Input cannot be empty." << std::endl;
		return false;
	}

	return true;
}

void PhoneBook::addContact()
{
	int	index;
	static int oldIndex = 0;

	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	if (!getInput("Enter first name: ", firstName)
		|| !getInput("Enter last name: ", lastName)
		|| !getInput("Enter nickname: ", nickname)
		|| !getInput("Enter phone number: ", phoneNumber)
		|| !getInput("Enter darkest secret: ", darkestSecret))
	{
		std::cout << "Contact not added." << std::endl;
		return ;
	}
	if (contactCount < 8)
		index = contactCount++;
	else
	{
		index = oldIndex;
		oldIndex = (oldIndex + 1) % 8;
	}
	contacts[index].setInfo(firstName, lastName, nickname, phoneNumber,
		darkestSecret);
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() const
{
	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	std::cout << "|" << std::setw(10) << "Index"
				<< "|";
	std::cout << std::setw(10) << "First Name"
				<< "|";
	std::cout << std::setw(10) << "Last Name"
				<< "|";
	std::cout << std::setw(10) << "Nickname"
				<< "|" << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << "|" << std::endl;
	}

	int index;
	std::string input;
	std::cout << "Enter index to display: ";
	std::getline(std::cin, input);

	std::stringstream ss(input);
	if (!(ss >> index) || !ss.eof())
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	if (index < 0 || index >= contactCount)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}

	contacts[index].displayContact();
}

std::string PhoneBook::truncate(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::displayText() const
{
	std::cout << "=== My Awesome PhoneBook ===" << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "  ADD    - Add a new contact" << std::endl;
	std::cout << "  SEARCH - Display a specific contact" << std::endl;
	std::cout << "  EXIT   - Quit the program" << std::endl;
	std::cout << "===========================" << std::endl;
}
