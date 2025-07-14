/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:41:27 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/11 15:42:01 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data() : id(0), name(""), value(0.0), active(false)
{
}

Data::Data(int id, const std::string &name, double value, bool active) : id(id),
	name(name), value(value), active(active)
{
}

Data::Data(const Data &other) : id(other.id), name(other.name),
	value(other.value), active(other.active)
{
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		id = other.id;
		name = other.name;
		value = other.value;
		active = other.active;
	}
	return (*this);
}

Data::~Data()
{
}

void Data::display() const
{
	std::cout << "Data { id: " << id << ", name: \"" 
	<< name << "\", value: " << value << ", active: " 
	<< (active ? "true" : "false") << " }" << std::endl;
}
