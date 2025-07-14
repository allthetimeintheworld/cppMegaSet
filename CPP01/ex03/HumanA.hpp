/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:37:10 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/04 16:11:34 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"
class HumanA
{
	private:
		std::string name;
		Weapon *weapon;	
	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void attack() const;
		void setWeapon(Weapon &newWeapon);
};

#endif