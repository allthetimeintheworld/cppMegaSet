/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:14:04 by jadyar            #+#    #+#             */
/*   Updated: 2025/05/31 17:06:46 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name()
{
	std::cout << "A zombie is born!" << std::endl;	
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is being ground to paste " << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiinnnzzzZ... are so 1846, I actually enjoy a nice Braise" << std::endl;
}
void Zombie::setName(std::string name)
{
	this->name = name;
}
