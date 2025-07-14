/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:21:21 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/18 13:22:25 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	// Methods for accessing ideas
	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;
};

#endif
