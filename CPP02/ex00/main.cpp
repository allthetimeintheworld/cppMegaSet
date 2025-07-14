/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:23:08 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/05 16:31:41 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;

	return (0);
}