/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:45:51 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 17:52:05 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called. Created unnamed ScavTrap." << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << getName() << " constructed and ready to guard!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << getName() << " cloned through copy construction!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " has been dismantled." << std::endl;
}

// Assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// Override attack method
void ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	if (getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << getName() << " is knocked out and cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << getName() << " aggressively attacks " << target << ", dealing " << getAttackDamage() << " points of damage! Energy remaining: " << getEnergyPoints() << std::endl;
}

// Special ability
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
}
