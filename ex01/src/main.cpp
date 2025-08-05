#include "../inc/Serializer.hpp"

int	main()
{
	Data data;

	data.val = 56236;
	data.str = "My lucky numbers";

	std::cout << "\nBefore serializing and deserealizing\n" <<
	"str: " << data.str << ", val: " << data.val << ", ptr: " << &data << std::endl;

	uintptr_t test = Serializer::serialize(&data);
	Data *data2 = Serializer::deserialize(test);


	std::cout << "\nAfter serializing and deserealizing\n" <<
	"str: " << data2->str << ", val: " << data2->val << ", ptr: " << data2 << std::endl;

	if (&data != data2){
		std::cout << "Pointers differ!" << std::endl;
	}
	else{
		std::cout << "Pointers are equal!" << std::endl;
	}

	Data data3;

	data3.val = -1;
	data3.str = "";

	std::cout << "\nBefore serializing and deserealizing\n" <<
	"str: " << data3.str << ", val: " << data3.val << ", ptr: " << &data3 << std::endl;

	uintptr_t test2 = Serializer::serialize(&data3);
	Data *data4 = Serializer::deserialize(test2);


	std::cout << "\nAfter serializing and deserealizing\n" <<
	"str: " << data4->str << ", val: " << data4->val << ", ptr: " << data4 << std::endl;

	if (&data3 != data4){
		std::cout << "Pointers differ!" << std::endl;
	}
	else{
		std::cout << "Pointers are equal!" << std::endl;
	}
	return (0);
}