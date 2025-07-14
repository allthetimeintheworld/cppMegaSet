/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:21:30 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 13:22:51 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called - 100 ideas initialized" << std::endl;
	// Initialize all ideas to empty strings
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called - deep copying ideas" << std::endl;
	// Deep copy of ideas
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		// Deep copy of ideas
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called - all ideas forgotten" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (ideas[index]);
	return ("");
}
