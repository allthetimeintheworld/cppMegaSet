/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:54:02 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/05 13:59:42 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}

	Harl Harl;
	std::string level = argv[1];
	Harl.complain(level);
	std::cout << "Harl has finished complaining." << std::endl;
	return (0);
}