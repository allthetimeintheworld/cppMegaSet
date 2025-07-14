/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:23:15 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/17 14:07:59 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixedPointValue;
	static const int	fractionalBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other); //overload assignment operator
	int getRawBits(void) const;
	void setRawBits(int const raw);

};



#endif