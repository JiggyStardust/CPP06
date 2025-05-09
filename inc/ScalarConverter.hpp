/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:42:55 by sniemela          #+#    #+#             */
/*   Updated: 2025/05/09 12:57:49 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
	public:
		static void converter(const std::string& literal);

	ScalarConverter() = delete;
    ~ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter&) = delete;
    ScalarConverter& operator=(const ScalarConverter&) = delete;
};