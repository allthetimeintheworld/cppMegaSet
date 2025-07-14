/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:13:52 by jadyar            #+#    #+#             */
/*   Updated: 2025/05/31 17:09:39 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "Zombie.hpp"

int main()
{
	int N = 5;
	std::cout << " Creating a heap Horde of " << N <<  "zombies" <<std::endl;
	Zombie *horde = zombieHorde(N, "Dave");
	for (int i = 0; i < N; i++)
	{
		std::cout << " Zombie " << i + 1 << " announces:";
		horde[i].announce();
	}

	std::cout << "Lets kill that heap horde!" << std::endl;
	delete[] horde;
	return(0);
}