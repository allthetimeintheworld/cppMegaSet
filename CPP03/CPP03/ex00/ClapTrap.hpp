/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:06:06 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 16:14:41 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
  private:
	std::string _name;	// Name of the ClapTrap instance	
	unsigned int _hitPoints;	// Health points (initialized to 10)
	unsigned int _energyPoints;// Energy points for actions (initialized to 10)
	unsigned int _attackDamage; // Damage dealt by attacks (initialized to 0)

  public:
	// Constructors & Destructor
	ClapTrap();							// Default constructor
	ClapTrap(const std::string &name);	// Parameterized constructor
	ClapTrap(const ClapTrap &other);	// Copy constructor
	~ClapTrap();						// Destructor

	// Assignment operator
	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
};

#endif
