/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:07:43 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 17:59:31 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	FragTrap	frag5;

	std::cout << "\n===== CLAPTRAP TESTS =====\n" << std::endl;
	ClapTrap bot1("CL4P-TP");
	bot1.attack("Bandit");
	bot1.takeDamage(3);
	bot1.beRepaired(2);
	std::cout << "\n===== SCAVTRAP TESTS =====\n" << std::endl;
	ScavTrap scav1("SC4V-TP");
	scav1.attack("Raider");
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	scav1.guardGate();
	std::cout << "\n===== FRAGTRAP TESTS =====\n" << std::endl;
	// Test case 1: FragTrap basic functionality
	std::cout << "\n===== TEST 1: FragTrap Basic Functionality =====\n" << std::endl;
	FragTrap frag1("FR4G-TP");
	frag1.attack("Psycho");
	frag1.takeDamage(40);
	frag1.beRepaired(25);
	frag1.highFivesGuys();
	// Test case 2: FragTrap construction and destruction chaining
	std::cout << "\n===== TEST 2: FragTrap Construction/Destruction Chaining =====\n" << std::endl;
	{
		std::cout << "Creating a FragTrap:" << std::endl;
		FragTrap frag2("Destroyer");
		std::cout << "FragTrap will be destroyed when leaving scope" << std::endl;
	}
	// Test case 3: FragTrap copy constructor and assignment
	std::cout << "\n===== TEST 3: FragTrap Copy Operations =====\n" << std::endl;
	FragTrap frag3("Original");
	FragTrap frag4(frag3); // Copy constructor
	frag5 = frag3; // Assignment operator
	frag3.attack("Enemy 1");
	frag4.attack("Enemy 2");
	frag5.attack("Enemy 3");
	// Test case 4: Demonstrate different attributes between trap types
	std::cout << "\n===== TEST 4: Comparing Different Trap Types =====\n" << std::endl;
	ClapTrap clap("Regular");
	ScavTrap scav("Guardian");
	FragTrap frag("Bomber");
	std::cout << "ClapTrap " << clap.getName() << " stats - HP: " << clap.getHitPoints() << ", Energy: " << clap.getEnergyPoints() << ", Attack: " << clap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap " << scav.getName() << " stats - HP: " << scav.getHitPoints() << ", Energy: " << scav.getEnergyPoints() << ", Attack: " << scav.getAttackDamage() << std::endl;
	std::cout << "FragTrap " << frag.getName() << " stats - HP: " << frag.getHitPoints() << ", Energy: " << frag.getEnergyPoints() << ", Attack: " << frag.getAttackDamage() << std::endl;
	std::cout << "\n===== End of Tests =====\n" << std::endl;
	return (0);
}
