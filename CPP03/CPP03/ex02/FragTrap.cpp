/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:01:00 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 17:57:27 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called. Created unnamed FragTrap." << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << getName() << " has been assembled and is ready to party!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << getName() << " duplicated through copy construction!" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " has exploded spectacularly!" << std::endl;
}

// Assignment operator
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// Special ability
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " enthusiastically requests high fives from everyone! Anyone? High five?" << std::endl;
}
