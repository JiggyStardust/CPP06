/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:09:21 by sniemela          #+#    #+#             */
/*   Updated: 2025/08/05 13:42:26 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

bool	strIsChar(const std::string &str)
{
	return (str.size() == 1 && std::isalpha(str[0]));
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
		throw std::runtime_error("impossible");
	}
	return (ret);
}

void	ToChar(const std::string &str)
{
	// try catch for unprintable characters
	try 
	{
		char val;
		if (str.size() == 1 && isalpha(str[0]))
		{
			val = static_cast<char>(str[0]);
		}
		else
		{
			try 
			{
				int value = floatAndDoubleToInt(str);
				if (value < CHAR_MIN || value > CHAR_MAX)
				{
					// std::cout << CHAR_MIN << "-" << CHAR_MAX << std::endl;
					throw std::runtime_error("Non displayable");
				}
				// std::cout << "value as int: " << value << std::endl;
				val = static_cast<char>(value);
				// std::cout << "val as char: " << val << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << "char: " << e.what() << std::endl;
				return ;
			}
			if (!std::isprint(val))
			{
				throw std::runtime_error("Non displayable");
			}
		}
		std::cout << "char: '" << val << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "char: " << e.what() << std::endl;
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

bool	strIsInt(const std::string &str)
{
	std::string::const_iterator it = str.begin();
	if (str[0] == '-')
	{
		it++;
	}
	while (it != str.end() && std::isdigit(*it))
	{
		it++;
	}
	return (!str.empty() && it == str.end());
}

void	intToInt(const std::string &str)
{	
	long long val;
	
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
		std::cout << "int: impossible: " << str << " " << e.what() << std::endl;
	}
}

void	intToFloat(const std::string &str)
{
	long long val;
	
	try 
	{
		val = std::stol(str);
		if (val < INT_MIN || val > INT_MAX){
			throw std::runtime_error("exceeds int limits");
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cout << "float: impossible: " << str << " " << e.what() << std::endl;
	}
}

void	intToDouble(const std::string &str)
{
	long long val;
	
	try 
	{
		val = std::stol(str);
		if (val < INT_MIN || val > INT_MAX){
			throw std::runtime_error("exceeds int limits");
		}
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl; 
	}
	catch (std::exception &e)
	{
		std::cout << "double: impossible: " << str << " " << e.what() << std::endl;
	}
}

bool	strIsFloat(const std::string &str)
{
	std::string temp = str;

	if (temp[0] == '-')
	{
		temp.erase(0, 1);
	}
	// std::cout << "temp: " << temp << std::endl;
	return (std::regex_match(temp, std::regex(R"(\d{1,39}\.\d{1,7}f)")));
}

void	floatToInt(const std::string &str)
{
	try 
	{
		int val = floatAndDoubleToInt(str);
		std::cout << "int: " << val << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "int: " << e.what() << std::endl;
		return ;
	}
}

int		getPrecision(const std::string &str)
{
	size_t pos = str.find(".");

	if (pos == std::string::npos)
	{
		return (1);
	}
	int ret = 0;
	while (str[pos + ret + 1])
	{
		ret++;
	}
	// std::cout << "STR: " << str << ", PRECISION: " << ret << std::endl;
	return (ret);
}

void	floatToFloat(const std::string &str)
{
	// std::cout << "float: " << str << "\n";
	std::string temp = str;
	temp.pop_back();
	try {
		float val = std::stof(temp);
		std::cout << "float: " << std::fixed << std::setprecision(getPrecision(temp)) << val << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "float: impossible\n";
	}
}


void	floatToDouble(const std::string &str)
{
	std::string temp = str;
	temp.pop_back();
	try {
		float val = std::stof(temp);
		std::cout << "double: " << std::fixed << std::setprecision(getPrecision(temp)) << static_cast<double>(val) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "double: impossible\n";
	}
	
}

bool	strIsDouble(const std::string &str)
{
	std::string temp = str;

	if (temp[0] == '-')
	{
		temp.erase(0, 1);
	}
	// std::cout << "temp: " << temp << std::endl;
	return (std::regex_match(temp, std::regex(R"(\d{1,309}\.\d{1,15})")));
}

void	doubleToInt(const std::string &str)
{
	try {
		int val = floatAndDoubleToInt(str);
		std::cout << "int: " << val << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "int: " << e.what() << std::endl;
	}
	
}

void	doubleToDouble(const std::string &str)
{
	// std::cout << "double: " << str << std::endl;

	try 
	{
		double val = std::stod(str);
		std::cout << "double: " << val << std::endl;
	}
	catch  (std::exception &e)
	{
		std::cout << "double: impossible: " << e.what() << std::endl;
		return ;
	}
}

void	doubleToFloat(const std::string &str)
{
	try 
	{
		double val = std::stod(str);
		std::cout << "float: " << std::fixed << std::setprecision(getPrecision(str)) << static_cast<float>(val) << "f\n";
	}
	catch  (std::exception &e)
	{
		std::cout << "float: impossible " << e.what() << std::endl;
		return ;
	}
}

void	handlePseudoLiterals(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	else if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << str << std::endl;
		if (str == "-inff"){
			std::cout << "double: -inf" << std::endl;
		}
		else if (str == "+inff"){
			std::cout << "double: inf" << std::endl;
		}
		else{
			std::cout << "double: nan" << std::endl;
		}
	}
}

void	ScalarConverter::convert(const std::string& literal)
{
	if (strIsChar(literal))
	{
		std::cout << "CHAR\n";
		ToChar(literal);
		charToInt(literal);
		charToFloat(literal);
		charToDouble(literal);
	}
	else if (strIsInt(literal))
	{
		std::cout << "INT\n";
		ToChar(literal);
		intToInt(literal);
		intToFloat(literal);
		intToDouble(literal);
	}
	else if (strIsFloat(literal))
	{
		std::cout << "FLOAT\n";
		ToChar(literal);
		floatToInt(literal);
		floatToFloat(literal);
		floatToDouble(literal);
	}
	else if (strIsDouble(literal))
	{
		std::cout << "DOUBLE\n";
		ToChar(literal);
		doubleToInt(literal);
		doubleToFloat(literal);
		doubleToDouble(literal);
	}
	// else if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
	// 			literal == "-inf" || literal == "+inf" || literal == "nan")
	// {
	// 	handlePseudoLiterals(literal);
	// 	// ToChar(literal);
	// 	// doubleToInt(literal);
	// 	// doubleToFloat(literal);
	// 	// doubleToDouble(literal);
	// }

	else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
	{
		// handlePseudoLiterals(literal);
		ToChar(literal);
		floatToInt(literal);
		floatToFloat(literal);
		floatToDouble(literal);
	}
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
	{
		// handlePseudoLiterals(literal);
		ToChar(literal);
		doubleToInt(literal);
		doubleToFloat(literal);
		doubleToDouble(literal);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}