/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:45:32 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 17:51:52 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
	// Constructors & Destructor
	ScavTrap();                        // Default constructor
	ScavTrap(const std::string &name); // Parameterized constructor
	ScavTrap(const ScavTrap &other);   // Copy constructor
	~ScavTrap();                       // Destructor

	// Assignment operator
	ScavTrap &operator=(const ScavTrap &other);

	// Methods
	void attack(const std::string &target); // Override attack method
	void guardGate();                       // Special ability
};

#endif
