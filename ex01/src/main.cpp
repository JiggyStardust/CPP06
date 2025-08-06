#include "../inc/Serializer.hpp"

int	main()
{
	try {
		Data data;

		data.val = 56236;
		data.str = "My lucky numbers";

		std::cout << "\n1. WORKS \n";
		std::cout << "\nBefore serializing and deserealizing\n" <<
		"str: " << data.str << ", val: " << data.val << ", ptr: " << &data << std::endl;

		uintptr_t test = Serializer::serialize(&data);
		Data *data2 = Serializer::deserialize(test);


		std::cout << "\nAfter serializing and deserealizing\n" <<
		"str: " << data2->str << ", val: " << data2->val << ", ptr: " << data2 << std::endl;

		if (&data != data2){
			std::cout << "\nPointers differ!" << std::endl;
		}
		else{
			std::cout << "\nPointers are equal!" << std::endl;
		}

		Data data3;

		data3.val = -1;
		data3.str = "";

		std::cout << "\n\n\n2. SENDING RUBBISH INSTEAD OF ORIGINAL VALUES\n";
		
		std::cout << "\nBefore serializing and deserealizing\n" <<
		"str: " << data3.str << ", val: " << data3.val << ", ptr: " << &data3 << std::endl;

		uintptr_t test2 = Serializer::serialize(&data3);
		Data *data4 = Serializer::deserialize(958732);
		(void)test2;

		std::cout << "\nAfter serializing and deserealizing random values\n";

		if (&data3 != data4){
			std::cout << "\nPointers differ!" << std::endl;
		}
		else{
			std::cout << "\nPointers are equal!" << std::endl;
		}
		}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}