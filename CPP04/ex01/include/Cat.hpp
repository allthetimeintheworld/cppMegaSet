/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:47:35 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 13:34:19 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	virtual void makeSound() const;
	Brain *getBrain() const; // same deep copy call
};

#endif
