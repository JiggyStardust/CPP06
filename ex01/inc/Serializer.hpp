#pragma once


#include <cstdint>
#include <iostream>
#include <string>

struct Data
{
	int	val;
	std::string str;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private: 
		Serializer() = delete;
		~Serializer() = delete;
		Serializer(const Serializer&) = delete;
		Serializer& operator=(const Serializer&) = delete;
};