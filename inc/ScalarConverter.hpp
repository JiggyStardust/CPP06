/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:42:55 by sniemela          #+#    #+#             */
/*   Updated: 2025/07/24 09:38:12 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

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