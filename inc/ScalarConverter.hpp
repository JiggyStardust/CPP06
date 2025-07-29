/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:42:55 by sniemela          #+#    #+#             */
/*   Updated: 2025/07/29 15:45:21 by saaraniemel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <climits>
#include <regex>
#include <sstream>

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);
	private:
		ScalarConverter() = delete;
    	~ScalarConverter() = delete;
    	ScalarConverter(const ScalarConverter&) = delete;
    	ScalarConverter& operator=(const ScalarConverter&) = delete;
};