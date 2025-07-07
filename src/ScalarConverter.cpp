/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:09:21 by sniemela          #+#    #+#             */
/*   Updated: 2025/07/07 12:09:33 by saaraniemel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	strIsChar(const std::string &str)
{
	return (str.size() == 1)
}

void	charToChar(const std::string &str)
{
	// try catch for unprintable characters
	try 
	{
		char val = static_cast<char>(str[0]);
		
	}
	catch (std::exception &e)
	{
		
		return ;
	}
	std::cout << "char: " << val << std::endl;
}

void	charToInt(const std::string &str)
{
	int val = static_cast<int>(str[0]);
	std::cout << "int: " << val << std::endl;
}

void	charToFloat(const std::string &str)
{
	int val = static_cast<float>(str[0]);
	std::cout << "float: " << val << std::endl;
}

void	charToDouble(const std::string &str)
{
	int val = static_cast<double>(str[0]);
	std::cout << "double: " << val << std::endl;
}

bool	strIsInt(const std::string &str)
{
	std::string::const_iterator it = str.begin();
	while (it != str.end() && std::isdigit(*it))
	{
		it++;
	}
	return (!str.empty() && it == str.end());
}

void	intToInt(const std::string &str)
{	
	long val;
	try 
	{
		val = std::stol(str);
		if (val < INT_MIN || val > INT_MAX){
			throw std::runtime_error("exceeds int limits");
		}
		std::cout << "int: " << static_cast<int>(val) << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cout << "Impossible: " << str << " " << e.what() << std::endl;
	}
}

void	intToChar(const std::string &str)
{
	
}

void	intToFloat(const std::string &str)
{
	
}

void	intToDouble(const std::string &str)
{
	
}

void	ScalarConverter::converter(const std::string& literal)
{
	// if string is empty or there something else wrong
	// if string is a special nanf etc case

	if (strIsChar(literal))
	{
		charToChar(literal);
		charToInt(literal);
		charToFloat(literal);
		charToDouble(literal);
	}
	else if (strIsInt(literal))
	{
		intToChar(literal);
		intToInt(literal);
		intToFloat(literal);
		intToDouble(literal);
	}

	bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
}