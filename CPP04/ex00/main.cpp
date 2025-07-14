/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:39:37 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 12:37:14 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// Test 1: Basic polymorphism with Animal class
	std::cout << "\n----- Test 1: Animal polymorphism -----\n" << std::endl;

	const Animal *meta = new Animal();
	const Animal *Spot = new Dog();
	const Animal *Mr_fluffy = new Cat();

	std::cout << Spot->getType() << " " << std::endl;
	std::cout << Mr_fluffy->getType() << " " << std::endl;

	Mr_fluffy->makeSound();
	Spot->makeSound();
	meta->makeSound();

	delete meta;
	delete Spot;
	delete Mr_fluffy;

	// Test 2: Demonstrating the lack of polymorphism in WrongAnimal class
	std::cout << "\n----- Test 2: WrongAnimal non-polymorphic behavior -----\n" << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound(); // will output the WrongAnimal sound,not the WrongCat sound
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	// Test 3: Additional test - direct instances
	std::cout << "\n----- Test 3: Direct instances -----\n" << std::endl;

	Dog dog;
	Cat cat;
	WrongCat directWrongCat;

	std::cout << dog.getType() << " says: ";
	dog.makeSound();

	std::cout << cat.getType() << " says: ";
	cat.makeSound();

	std::cout << directWrongCat.getType() << " says directly: ";
	directWrongCat.makeSound();
		// Will output WrongCat sound when called directly

	return (0);
}