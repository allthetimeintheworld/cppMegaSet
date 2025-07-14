/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:40:47 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/11 16:40:51 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*generate(void)
{
	static bool	seeded = false;
	int			random;

	// Initialize random seed once
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	random = std::rand() % 3;
	switch (random)
	{
	case 0:
		std::cout << "Generated: A" << std::endl;
		return (new A());
	case 1:
		std::cout << "Generated: B" << std::endl;
		return (new B());
	case 2:
		std::cout << "Generated: C" << std::endl;
		return (new C());
	default:
		return (new A());
	}
}

void	identify(Base *p)
{
	if (!p)
	{
		std::cout << "NULL pointer" << std::endl;
		return ;
	}
	// Try to cast to each type using dynamic_cast
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Unknown type" << std::endl;
	}
}

void	identify(Base &p)
{
	// Cannot use pointers, so we use try-catch with dynamic_cast
	// dynamic_cast with references throws std::bad_cast if it fails
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a; // Suppress unused variable warning
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &)
	{
		// Not type A, continue
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b; // Suppress unused variable warning
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &)
	{
		// Not type B, continue
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c; // Suppress unused variable warning
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &)
	{
		// Not type C
	}
	std::cout << "Unknown type" << std::endl;
}
