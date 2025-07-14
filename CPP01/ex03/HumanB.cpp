/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:37:13 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/04 14:49:06 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <string>

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL)
{
	std::cout << "HumanB '" << name << "' created." << std::endl;
}
void HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "." << std::endl;
	else
		std::cout << name << " has no weapon to attack with." << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
	std::cout << name << " has set their weapon to '" << weapon->getType() << "'." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB '" << name << "' destroyed." << std::endl;
}
