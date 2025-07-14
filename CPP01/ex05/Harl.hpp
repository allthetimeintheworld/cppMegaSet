/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:53:59 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/05 14:06:23 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <string>
#include <iostream>

class Harl {
public:
	Harl();
	~Harl();
	void debug();
	void info();
	void warning();
	void error();
	void complain(const std::string &level);
private:
	void (Harl::*functions[4])();
	std::string levels[4];
	Harl(const Harl &other);
	//Harl &operator=(const Harl &other);

};


#endif