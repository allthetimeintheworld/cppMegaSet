/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:53:37 by jadyar            #+#    #+#             */
/*   Updated: 2025/05/31 16:56:01 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}
