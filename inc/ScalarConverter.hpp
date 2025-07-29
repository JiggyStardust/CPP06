/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:42:55 by sniemela          #+#    #+#             */
/*   Updated: 2025/07/29 10:39:34 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <climits>

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