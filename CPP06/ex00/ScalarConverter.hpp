/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:34:57 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/10 15:58:32 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <climits>
#include <sstream>

class ScalarConverter
{
private:
	// Private constructor to prevent instantiation
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	// Helper methods
	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isPseudoLiteral(const std::string& literal);
	
	static void convertFromChar(char c);
	static void convertFromInt(int value);
	static void convertFromFloat(float value);
	static void convertFromDouble(double value);
	static void handlePseudoLiteral(const std::string& literal);
	static void printImpossible();
	static void printCharOutput(double value);
	static void printIntOutput(double value);
	static void printFloatOutput(double value, bool isNan, bool isInf);
	static void printDoubleOutput(double value, bool isNan, bool isInf);

public:
	static void convert(const std::string& literal);
};

#endif
