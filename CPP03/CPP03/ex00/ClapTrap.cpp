/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:47 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 16:11:26 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called. Created unnamed ClapTrap." << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed and ready for action!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
	_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " cloned through copy construction!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

// Attack method
void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy and cannot attack!" << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is knocked out and cannot attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! Energy remaining: " << _energyPoints << std::endl;
}

// Take damage method
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already knocked out and can't take more damage!" << std::endl;
		return ;
	}
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage and is knocked out!" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " damage! Hit points remaining: " << _hitPoints << std::endl;
	}
}

// Repair method
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy and cannot repair itself!" << std::endl;
		return ;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is knocked out and cannot repair itself!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Current HP: " << _hitPoints << ", Energy remaining: " << _energyPoints << std::endl;
}

// Getters
std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}
