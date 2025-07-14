/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:30:25 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/05 12:32:20 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string replaceAll(const std::string &content, const std::string &s1,
	const std::string &s2)
{
	size_t	lastPos;
	size_t	findPos;

	std::string result;
	lastPos = 0;
	if (s1.empty())
		return (content);
	while ((findPos = content.find(s1, lastPos)) != std::string::npos)
	{
		result.append(content, lastPos, findPos - lastPos);
		result += s2;
		lastPos = findPos + s1.length();
	}
	result.append(content, lastPos, content.length() - lastPos);
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of arguments." << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: Search string cannot be empty." << std::endl;
		return (1);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file '" << filename << "'." << std::endl;
		return (1);
	}
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file '" << outputFilename << "'." << std::endl;
		inputFile.close();
		return (1);
	}
	std::string content;
	std::string line;
	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
		{
			content += '\n';
		}
	}
	std::string modifiedContent = replaceAll(content, s1, s2);
	outputFile << modifiedContent;
	inputFile.close();
	outputFile.close();
	std::cout << "Replacement complete. Output written to '" << outputFilename << "'." << std::endl;
	return (0);
}
