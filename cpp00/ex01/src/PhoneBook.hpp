#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
  private:
	Contact contacts[8];
	int contactCount;
	std::string truncate(const std::string &str) const ;
	bool getInput(const std::string &prompt, std::string &input);

  public:
	PhoneBook();
	void addContact();
	void searchContact() const;
	void displayText() const;
};

#endif