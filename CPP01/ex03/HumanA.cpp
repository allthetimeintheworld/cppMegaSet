/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:37:05 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/04 15:56:52 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>

HumanA::HumanA(const std::string &name, Weapon &weapon) 
	: name(name), weapon(&weapon)
{
	std::cout << "HumanA '" << name << "' created with weapon of type '" << weapon.getType() << "'." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA '" << name << "' destroyed." << std::endl;
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon->getType() << "." << std::endl;
}

void HumanA::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
	std::cout << name << " has changed their weapon to '" << weapon->getType() << "'." << std::endl;
}