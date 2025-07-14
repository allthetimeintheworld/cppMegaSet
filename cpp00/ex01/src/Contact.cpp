#include "Contact.hpp"
#include <iostream>
#include <string>

/*
Class implementation for Contact
construct and init
setters and getters methods for everything
*/

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkestSecret = "";
}

void Contact::setFirstName(const std::string &name)
{
	firstName = name;
}

void Contact::setLastName(const std::string &name)
{
	lastName = name;
}

void Contact::setNickname(const std::string &name)
{
	nickname = name;
}

void Contact::setPhoneNumber(const std::string &number)
{
	phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string &secret)
{
	darkestSecret = secret;
}

void Contact::setInfo(const std::string &first, const std::string &last,
					const std::string &nick, const std::string &phone, 
					const std::string &secret)

{
	setFirstName(first);
	setLastName(last);
	setNickname(nick);
	setPhoneNumber(phone);
	setDarkestSecret(secret);
}
std::string Contact::getFirstName() const
{
	return (firstName);
}

std::string Contact::getLastName() const
{
	return (lastName);
}

std::string Contact::getNickname() const
{
	return (nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return (darkestSecret);
}

void Contact::displayContact() const
{
	std::cout << "First name" << firstName << std::endl;
	std::cout << "Last name " << lastName << std::endl;
	std::cout << " Nickname " << nickname << std::endl;
	std::cout << " Phone number " << phoneNumber << std::endl;
	std::cout << " Darkest Secret " << darkestSecret << std::endl;
}
