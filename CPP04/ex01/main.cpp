/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:39:37 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 15:32:26 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// Test 1: Basic polymorphism with memory leak check
	std::cout << "\n----- Test 1: Basic memory leak check -----\n" << std::endl;
	const Animal *spot = new Dog();
	const Animal *mrFluffy = new Cat();

	std::cout << "Spot says: ";
	spot->makeSound();
	std::cout << "Mr Fluffy says: ";
	mrFluffy->makeSound();

	delete spot;
	delete mrFluffy;

	// Test 2: Array of Animals
	std::cout << "\n----- Test 2: Array of Animals -----\n" << std::endl;
	int arraySize = 4; 
	Animal *petShop[arraySize];
	std::string petNames[4] = {"Buddy", "Champ", "Dave", "Dog"};

	// Fill half with Dogs, half with Cats
	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
		{
			std::cout << "\nCreating Dog '" << petNames[i] << "'" << std::endl;
			petShop[i] = new Dog();
		}
		else
		{
			std::cout << "\nCreating Cat '" << petNames[i] << "'" << std::endl;
			petShop[i] = new Cat();
		}
	}

	// Make all animals sound
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << petNames[i] << " says: ";
		petShop[i]->makeSound();
	}

	// Delete all animals creatred in loop
	std::cout << "\n----- Deleting all pets from the pet shop -----\n" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "\nSaying goodbye to " << petNames[i] << std::endl;
		delete petShop[i]; // Should call the appropriate destructor
	}

	// Test 3: Deep Copy Test
	std::cout << "\n----- Test 3: Deep Copy with Copy Constructor -----\n" << std::endl;
	Dog *fido = new Dog();

	// Add some ideas to the dog's brain
	fido->getBrain()->setIdea(0, "I want to chase squirrels");
	fido->getBrain()->setIdea(1, "I love my human");

	// Create a copy using copy constructor
	std::cout << "\nCloning Fido to create Spot" << std::endl;
	Dog *spot2 = new Dog(*fido);

	// Show that the ideas were copied (deep copy)
	std::cout << "Fido's thought: " << fido->getBrain()->getIdea(0) << std::endl;
	std::cout << "Spot's thought: " << spot2->getBrain()->getIdea(0) << std::endl;

	// Change an idea in the copy and show they're separate
	std::cout << "\nSpot develops his own thoughts!" << std::endl;
	spot2->getBrain()->setIdea(0, "I want to sleep all day");

	std::cout << "Fido's thought: " << fido->getBrain()->getIdea(0) << std::endl;
	std::cout << "Spot's thought: " << spot2->getBrain()->getIdea(0) << std::endl;

	delete fido;
	delete spot2;

	// Test 4: Assignment Operator Test
	std::cout << "\n----- Test 4: Deep Copy with Assignment Operator -----\n" << std::endl;
	Cat *whiskers = new Cat();
	Cat *mittens = new Cat();

	// Add an idea to the original cat
	whiskers->getBrain()->setIdea(0, "I want to sleep in the sun");

	// Use assignment operator
	std::cout << "\nMaking Mittens think like Whiskers" << std::endl;
	*mittens = *whiskers;

	// Show they have the same ideas initially
	std::cout << "Whiskers thinks: " << whiskers->getBrain()->getIdea(0) << std::endl;
	std::cout << "Mittens thinks: " << mittens->getBrain()->getIdea(0) << std::endl;

	// Change the assigned cat's idea
	std::cout << "\nMittens develops independent thoughts!" << std::endl;
	mittens->getBrain()->setIdea(0, "I want tuna fish");

	std::cout << "Whiskers still thinks: " << whiskers->getBrain()->getIdea(0) << std::endl;
	std::cout << "Mittens now thinks: " << mittens->getBrain()->getIdea(0) << std::endl;

	delete whiskers;
	delete mittens;

	return (0);
}