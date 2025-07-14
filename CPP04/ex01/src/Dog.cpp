/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:47:09 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 13:30:13 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called - but now smart" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain); // so the deep copy is allocated here: i dont need you malloc!
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain); // this assignment bs is getting confusing
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (brain);
}
