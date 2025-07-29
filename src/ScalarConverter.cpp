/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:09:21 by sniemela          #+#    #+#             */
/*   Updated: 2025/07/29 16:08:40 by saaraniemel      ###   ########.fr       */
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
	try{
		ret = std::stoi(temp);
	}
	catch (std::exception &e)
	{
		// std::cout << e.what() << ": couldn't convert to int\n";
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
		if (str.size() == 1 && isprint(str[0]))
		{
			val = static_cast<char>(str[0]);
		}
		else
		{
			try 
			{
				int value = floatAndDoubleToInt(str);
				// std::cout << "value as int: " << value << std::endl;
				val = static_cast<char>(value);
				// std::cout << "val as char: " << val << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << "char: " << e.what() << std::endl;
				return ;
			}
			if (!isprint(val))
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
		std::cout << "int: impossible: " << str << " " << e.what() << std::endl;
	}
}

void	intToFloat(const std::string &str)
{
	// SHOULD WE CONVERT IF EXCEEDS FLOAT'S OR INTS LIMITS?
	std::cout << "float: " << str << ".0f" << std::endl;
}

void	intToDouble(const std::string &str)
{
	std::cout << "double: " << str << ".0" << std::endl;
}

// bool is_number(const std::string& s)
// {
// std::string::const_iterator it = s.begin();
// while (it != s.end() && std::isdigit(*it)) ++it;
// return !s.empty() && it == s.end();
// }

bool	strIsFloat(const std::string &str)
{
	return (std::regex_match(str, std::regex(R"(\d{1,39}\.\d{1,7}f)")));
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

void	floatToFloat(const std::string &str)
{
	std::cout << "float: " << str << "\n"; 
}

void	floatToDouble(const std::string &str)
{
	std::string temp = str;
	temp.pop_back();
	
	std::cout << "double: " << temp << std::endl;
}

bool	strIsDouble(const std::string &str)
{
	return (std::regex_match(str, std::regex(R"(\d{1,309}\.\d{1,15})")));
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
	std::cout << "double: " << str << std::endl;

	// try 
	// {
	// 	double val = std::stod(str);
	// 	std::cout << "double: " << val << std::endl;
	// }
	// catch  (std::exception &e)
	// {
	// 	std::cout << "double: impossible: " << e.what() << std::endl;
	// 	return ;
	// }
}

void	doubleToFloat(const std::string &str)
{
	try 
	{
		double val = std::stod(str);
		std::cout << "float: " << static_cast<float>(val) << "f\n";
	}
	catch  (std::exception &e)
	{
		std::cout << "float: impossible " << e.what() << std::endl;
		return ;
	}
}

void	ScalarConverter::convert(const std::string& literal)
{
	// if string is empty or there something else wrong
	// if string is a special nanf etc case

	if (strIsChar(literal))
	{
		std::cout << "CHAR\n";
		ToChar(literal); // Prints even is above or under ASCIIS
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
		floatToFloat(literal); // need to get and set precision
		floatToDouble(literal);
	}
	else if (strIsDouble(literal))
	{
		std::cout << "DOUBLE\n";
		ToChar(literal);
		doubleToInt(literal);
		doubleToDouble(literal); // need to get and set precision
		doubleToFloat(literal);
	}
}