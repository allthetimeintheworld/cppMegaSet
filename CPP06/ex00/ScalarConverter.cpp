/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:35:22 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/11 15:41:39 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Private constructor - class cannot be instantiated
ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}
ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isChar(const std::string &literal)
{
	return (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'');//figure out size vs lenght
}

bool ScalarConverter::isInt(const std::string &literal)
{
	size_t	start;

	if (literal.empty())
		return (false);
	start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	if (start >= literal.size())
		return (false);
	for (size_t i = start; i < literal.size(); i++)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	size_t	start;
	bool	hasDot;
	bool	hasDigit;

	if (literal.size() < 2 || literal[literal.size() - 1] != 'f')
		return (false);
	std::string no_f = literal.substr(0, literal.size() - 1);
	start = 0;
	hasDot = false;
	hasDigit = false;
	if (no_f[0] == '+' || no_f[0] == '-')
		start = 1;
	if (start >= no_f.size())
		return (false);
	for (size_t i = start; i < no_f.size(); i++)
	{
		if (no_f[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(no_f[i]))
		{
			hasDigit = true;
		}
		else
		{
			return (false);
		}
	}
	return (hasDigit);
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	size_t	start;
	bool	hasDot;

	if (literal.empty())
		return (false);
	start = 0;
	hasDot = false;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	if (start >= literal.size())
		return (false);
	for (size_t i = start; i < literal.size(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
		{
			return (false);
		}
	}
	return (hasDot);
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	return literal == "nan" || literal == "+inf" || literal == "-inf"
		|| literal == "nanf" || literal == "+inff" || literal == "-inff";
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printCharOutput(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
	{
		std::cout << "impossible" << std::endl;
	}
	else if (std::isprint(static_cast<char>(value)))
	{
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
}

void ScalarConverter::printIntOutput(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::printFloatOutput(double value, bool isNan, bool isInf)
{
	std::cout << "float: ";
	if (isNan)
	{
		std::cout << "nanf" << std::endl;
	}
	else if (isInf)
	{
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::printDoubleOutput(double value, bool isNan, bool isInf)
{
	std::cout << "double: ";
	if (isNan)
	{
		std::cout << "nan" << std::endl;
	}
	else if (isInf)
	{
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void ScalarConverter::convertFromChar(char c)
{
	// For char literals, we know the char is displayable (per requirements)
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	
	double value = static_cast<double>(c);
	printFloatOutput(value, false, false);
	printDoubleOutput(value, false, false);
}

void ScalarConverter::convertFromInt(int value)
{
	std::cout << "char: ";
	if (value < 0 || value > 127)
	{
		std::cout << "impossible" << std::endl;
	}
	else if (std::isprint(static_cast<char>(value)))
	{
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
	double doubleValue = static_cast<double>(value);
	bool isNan = std::isnan(value);
	bool isInf = std::isinf(value);
	
	printCharOutput(doubleValue);
	std::cout << "int: ";
	if (isNan || isInf || value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(value) << std::endl;
	}
	printFloatOutput(doubleValue, isNan, isInf);
	printDoubleOutput(doubleValue, isNan, isInf);
}

void ScalarConverter::convertFromDouble(double value)
{
	bool isNan = std::isnan(value);
	bool isInf = std::isinf(value);
	
	printCharOutput(value);
	printIntOutput(value);
	printFloatOutput(value, isNan, isInf);
	printDoubleOutput(value, isNan, isInf);
}

void ScalarConverter::handlePseudoLiteral(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nanf" || literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inff" || literal == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inff" || literal == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoLiteral(literal))
	{
		handlePseudoLiteral(literal);
	}
	else if (isChar(literal))
	{
		convertFromChar(literal[1]);
	}
	else if (isInt(literal))
	{
		try
		{
			std::istringstream iss(literal);
			long long value;
			iss >> value;
			if (iss.fail() || !iss.eof() || value < INT_MIN || value > INT_MAX)
			{
				printImpossible();
			}
			else
			{
				convertFromInt(static_cast<int>(value));
			}
		}
		catch (const std::exception &e)
		{
			printImpossible();
		}
	}
	else if (isFloat(literal))
	{
		try
		{
			// Remove the 'f' suffix for parsing
			std::string no_f = literal.substr(0, literal.size() - 1);
			std::istringstream iss(no_f);
			float value;
			iss >> value;
			if (iss.fail() || !iss.eof())
			{
				printImpossible();
			}
			else
			{
				convertFromFloat(value);
			}
		}
		catch (const std::exception &e)
		{
			printImpossible();
		}
	}
	else if (isDouble(literal))
	{
		try
		{
			std::istringstream iss(literal);
			double value;
			iss >> value;
			if (iss.fail() || !iss.eof())
			{
				printImpossible();
			}
			else
			{
				convertFromDouble(value);
			}
		}
		catch (const std::exception &e)
		{
			printImpossible();
		}
	}
	else
	{
		printImpossible();
	}
}