/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:23:15 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 14:24:01 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int fixedPointValue;
	static const int fractionalBits = 8;

  public:
	// Constructors and destructors
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	Fixed(const int intValue);
	Fixed(const float floatValue);

	// Assignment operator
	Fixed &operator=(const Fixed &other);

	// Comparison operators
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Increment/decrement operators
	Fixed &operator++();   // Pre-increment
	Fixed operator++(int); // Post-increment
	Fixed &operator--();   // Pre-decrement
	Fixed operator--(int); // Post-decrement

	// Accessor methods
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Conversion methods
	float toFloat(void) const;
	int toInt(void) const;

	// Static member functions
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif