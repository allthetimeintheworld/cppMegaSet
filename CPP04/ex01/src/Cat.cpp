/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:49:45 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 13:37:29 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called - less smart then dog" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called but now with 100% more brain" << std::endl;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (brain);
}
