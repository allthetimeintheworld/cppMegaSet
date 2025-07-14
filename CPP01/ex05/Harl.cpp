/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:53:56 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/05 14:06:01 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() 
{
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
} 

Harl::Harl(const Harl &other)
{
	(void)other;
}

Harl::~Harl() 
{
	std::cout << "Harl destructor called." << std::endl;
}
void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I know the owner" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe more food costs more money. Give me more!" << std::endl;
}
void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I. Want. To. See. The MANGERERERERER" << std::endl;
}
void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! Don't you know who I am" << std::endl;
}

void Harl::complain(const std::string &level)
{

	for (int i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "[ No valid complaint ]" << std::endl;
}
