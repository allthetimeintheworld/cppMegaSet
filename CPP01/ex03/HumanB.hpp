/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:37:15 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/04 16:02:44 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include <string>

#include "Weapon.hpp"
class HumanB {
private:
	std::string name;
	Weapon *weapon; 
public:
	HumanB(const std::string &name);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon &newWeapon);
};

#endif