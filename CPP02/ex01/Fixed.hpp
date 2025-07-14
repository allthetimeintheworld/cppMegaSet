/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:23:15 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 14:17:37 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <cctype>
# include <cfloat>
# include <cmath>
# include <iostream>
# include <limits>

class Fixed
{
  private:
	int fixedPointValue;
	static const int fractionalBits = 8;

  public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

// Stream insertion operator declaration
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif