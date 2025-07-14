/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:37:26 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/02 17:50:51 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
class Weapon {
private:
	std::string type;
public:
	Weapon(const std::string &type);
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string &newType);
};

#endif