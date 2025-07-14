/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:47:22 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 12:33:08 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	virtual void makeSound() const;
};

#endif
