/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:42:55 by sniemela          #+#    #+#             */
/*   Updated: 2025/07/07 11:01:54 by saaraniemel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
	public:
		void converter(const std::string& literal);
	private:
		ScalarConverter() = delete;
    	~ScalarConverter() = delete;
    	ScalarConverter(const ScalarConverter&) = delete;
    	ScalarConverter& operator=(const ScalarConverter&) = delete;
};