/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:23:08 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 14:32:22 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	// Additional tests to demonstrate other operators
	Fixed c(3.14f);
	Fixed d(2.71f);

	std::cout << "\nAdditional tests if you even care:" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c + d = " << (c + d) << std::endl;
	std::cout << "c - d = " << (c - d) << std::endl;
	std::cout << "c * d = " << (c * d) << std::endl;
	std::cout << "c / d = " << (c / d) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;
	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;

	return (0);
}