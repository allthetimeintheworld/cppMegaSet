/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:47:22 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 13:25:20 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	virtual void makeSound() const;
	Brain *getBrain() const; //gotta test the deep copy 
};

#endif
