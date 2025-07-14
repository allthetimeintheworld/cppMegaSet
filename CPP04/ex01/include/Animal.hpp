/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:44:29 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 11:50:52 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif
