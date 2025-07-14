/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:14:08 by jadyar            #+#    #+#             */
/*   Updated: 2025/05/31 16:36:22 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cctype>
#include <iostream>

class Zombie
{
	private:
		std::string name;


	public:
	Zombie();
	Zombie(std::string name);

	~Zombie();
	
	void announce(void);
	void setName(std:: string name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif