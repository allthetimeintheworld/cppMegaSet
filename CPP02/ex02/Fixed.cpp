/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:26:10 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 14:30:48 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
		// Commented out for less output
}

Fixed::Fixed(const Fixed &other) : fixedPointValue(other.fixedPointValue)
{
	// std::cout << "Copy constructor called" << std::endl;
		// Commented out for less output
}

Fixed::Fixed(const int intValue) : fixedPointValue(intValue << fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
		// Commented out for less output
}

Fixed::Fixed(const float floatValue) : fixedPointValue(roundf(floatValue
		* (1 << fractionalBits)))
{
	// std::cout << "Float constructor called" << std::endl;
		// Commented out for less output
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
		// Commented out for less output
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
		// Commented out for less output
	if (this != &other)
	{
		this->fixedPointValue = other.fixedPointValue;
	}
	return (*this);
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return (this->fixedPointValue > other.fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->fixedPointValue < other.fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->fixedPointValue >= other.fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->fixedPointValue <= other.fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->fixedPointValue == other.fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->fixedPointValue != other.fixedPointValue);
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

// Increment/decrement operators
Fixed &Fixed::operator++() // Pre-increment
{
	this->fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++(int) // Post-increment
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--() // Pre-decrement
{
	this->fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

// Accessor methods
int Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

// Conversion methods
float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointValue) / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> fractionalBits);
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}