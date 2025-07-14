/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:53:54 by jadyar            #+#    #+#             */
/*   Updated: 2025/05/30 15:53:59 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.size(); j++)
				std::cout << (char)toupper(str[j]);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
