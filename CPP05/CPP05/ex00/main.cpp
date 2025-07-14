/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:29:49 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/30 12:33:16 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat dave("Dave", -89);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment:" << dave << std::endl;
		dave.decrementGrade();
		std::cout << "After decrement:" << dave << std::endl;

		//Bureaucrat invalid("Invalid", 0);
	}
	catch (std::exception &e)
	{
		std::cout <<"Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
