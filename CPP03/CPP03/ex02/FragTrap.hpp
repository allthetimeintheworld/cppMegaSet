/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:00:30 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 17:57:36 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
	// Constructors & Destructor
	FragTrap();                        // Default constructor
	FragTrap(const std::string &name); // Parameterized constructor
	FragTrap(const FragTrap &other);   // Copy constructor
	~FragTrap();                       // Destructor

	// Assignment operator
	FragTrap &operator=(const FragTrap &other);

	// Special ability
	void highFivesGuys(void);
};

#endif
