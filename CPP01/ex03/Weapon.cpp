/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:37:23 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/04 15:53:46 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{
	std::cout << "Weapon of type '" << type << "' created." << std::endl;
}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &newType) 
{
	std::cout << "Weapon type changed from '" << type << "' to '" << newType << "'." << std::endl;
	type = newType;
}

Weapon::~Weapon()
{
	std::cout << "Weapon of type '" << type << "' destroyed." << std::endl;
}
