/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:13:52 by jadyar            #+#    #+#             */
/*   Updated: 2025/05/31 15:47:10 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "Zombie.hpp"

int main()
{
	std::cout << " Creating Zombies on the heap: " << std::endl;
	Zombie *heapZombie = newZombie("Dave");
	heapZombie->announce();

	std::cout << "Now Stack based Zombies that must be destroyed:" << std::endl;
	randomChump("Stack Stackson");

	std::cout << "Stacks are gone! but the heapers stay until the end." << std::endl;
	heapZombie->announce();

	std::cout << "Lets kill those heap bastards!" << std::endl;
	delete heapZombie;
	return(0);
}