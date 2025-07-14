/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:41:13 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/11 15:41:15 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Private constructor - prevents instantiation
Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
