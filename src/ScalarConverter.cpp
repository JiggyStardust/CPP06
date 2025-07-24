/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:09:21 by sniemela          #+#    #+#             */
/*   Updated: 2025/07/24 13:41:52 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

bool	strIsChar(const std::string &str)
{
	return (str.size() == 1);
}

int		floatAndDoubleToInt(const std::string &str)
{
	std::string temp = str;
	int ret = 0;

	if (temp.back() == 'f')
	{
		temp.pop_back();
	}
	try 
	{
		ret = std::stoi(temp);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (ret);
}

void	ToChar(const std::string &str)
{
	// try catch for unprintable characters
	try 
	{
		char val;
		if (str.size() == 1 && isprint(str[0]))
		{
			val = static_cast<char>(str[0]);
		}
		else
		{
			int value = floatAndDoubleToInt(str);
			val = static_cast<char>(value);
			if (!isprint(val))
			{
				throw std::runtime_error("unprintable character: ");
			}
		}
		std::cout << "char: '" << val << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << str << std::endl;
	}
}

void	charToInt(const std::string &str)
{
	int val = static_cast<int>(str[0]);
	std::cout << "int: " << val << std::endl;
}

void	charToFloat(const std::string &str)
{
	int val = static_cast<float>(str[0]);
	std::cout << "float: " << val << "f" << std::endl;
}

void	charToDouble(const std::string &str)
{
	int val = static_cast<double>(str[0]);
	std::cout << "double: " << val << std::endl;
}

// bool	strIsInt(const std::string &str)
// {
// 	std::string::const_iterator it = str.begin();
// 	while (it != str.end() && std::isdigit(*it))
// 	{
// 		it++;
// 	}
// 	return (!str.empty() && it == str.end());
// }

// void	intToInt(const std::string &str)
// {	
// 	long val;
// 	try 
// 	{
// 		val = std::stol(str);
// 		if (val < INT_MIN || val > INT_MAX){
// 			throw std::runtime_error("exceeds int limits");
// 		}
// 		std::cout << "int: " << static_cast<int>(val) << std::endl; 
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Impossible: " << str << " " << e.what() << std::endl;
// 	}
// }

// void	intToChar(const std::string &str)
// {
	
// }

// void	intToFloat(const std::string &str)
// {
	
// }

// void	intToDouble(const std::string &str)
// {
	
// }

// bool is_number(const std::string& s)
// {
// std::string::const_iterator it = s.begin();
// while (it != s.end() && std::isdigit(*it)) ++it;
// return !s.empty() && it == s.end();
// }
void	ScalarConverter::convert(const std::string& literal)
{
	// if string is empty or there something else wrong
	// if string is a special nanf etc case

	if (strIsChar(literal))
	{
		ToChar(literal);
		charToInt(literal);
		charToFloat(literal);
		charToDouble(literal);
	}
	ToChar(literal);
	// else if (strIsInt(literal))
	// {
	// 	intToChar(literal);
	// 	intToInt(literal);
	// 	intToFloat(literal);
	// 	intToDouble(literal);
	// }

}