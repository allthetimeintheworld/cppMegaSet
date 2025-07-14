/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:07:43 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 17:49:29 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "\n===== CLAPTRAP TESTS =====\n" << std::endl;

	ClapTrap bot6;

	// Test case 1: Basic functionality
	std::cout << "\n===== TEST 1: Basic Functionality =====\n" << std::endl;
	ClapTrap bot1("CL4P-TP");
	bot1.attack("Bandit");
	bot1.takeDamage(3);
	bot1.beRepaired(2);

	// Test case 2: Running out of energy
	std::cout << "\n===== TEST 2: Energy Depletion =====\n" << std::endl;
	ClapTrap bot2("Energy-Test");
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Attack #" << (i + 1) << ": ";
		bot2.attack("Target Dummy");
	}
	// Should fail - out of energy
	bot2.attack("Target Dummy");
	bot2.beRepaired(5);

	// Test case 3: Getting knocked out
	std::cout << "\n===== TEST 3: Getting Knocked Out =====\n" << std::endl;
	ClapTrap bot3("HP-Test");
	bot3.takeDamage(5);
	bot3.attack("Enemy");
	bot3.takeDamage(10);  // This should knock out bot3
	bot3.attack("Enemy"); // Should fail - knocked out
	bot3.beRepaired(5);   // Should fail - knocked out

	// Test case 4: Copy constructor and assignment operator
	std::cout << "\n===== TEST 4: Copy Operations =====\n" << std::endl;
	ClapTrap bot4("Original");
	bot4.attack("Someone");
	ClapTrap bot5(bot4); // Copy constructor
	bot5.attack("Someone else");
	bot6 = bot4; // Assignment operator
	bot6.attack("A third person");

	std::cout << "\n===== SCAVTRAP TESTS =====\n" << std::endl;

	// Test case 5: ScavTrap basic functionality
	std::cout << "\n===== TEST 5: ScavTrap Basic Functionality =====\n" << std::endl;
	ScavTrap scav1("SC4V-TP");
	scav1.attack("Raider");
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	scav1.guardGate();

	// Test case 6: ScavTrap construction and destruction chaining
	std::cout << "\n===== TEST 6: ScavTrap Construction/Destruction Chaining =====\n" << std::endl;
	{
		std::cout << "Creating a ScavTrap:" << std::endl;
		ScavTrap scav2("Guardian");
		std::cout << "ScavTrap will be destroyed when leaving scope" << std::endl;
	}

	// Test case 7: ScavTrap copy constructor and assignment
	std::cout << "\n===== TEST 7: ScavTrap Copy Operations =====\n" << std::endl;
	ScavTrap scav3("Prototype");
	ScavTrap scav4(scav3); // Copy constructor
	ScavTrap scav5;
	scav5 = scav3; // Assignment operator

	scav3.attack("Enemy 1");
	scav4.attack("Enemy 2");
	scav5.attack("Enemy 3");

	std::cout << "\n===== End of Tests =====\n" << std::endl;
	return (0);
}