/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:37:19 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/04 15:59:53 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main()
{

	{
		Weapon club = Weapon("Religious Mace");
		HumanA sophie("Sophie", club);
		sophie.attack();
		club.setType("Tec9 with extended magazine");
		sophie.attack();
	}
	{
		Weapon club = Weapon("Billy Club");
		HumanB trey("Trey");
		trey.attack();
		trey.setWeapon(club);
		club.setType("p90 with tracer rounds");
		trey.attack();
	}
	return 0;
}
