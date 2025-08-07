#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate()
{
	std::srand(std::time(0));
	int mod = rand() % 3;

	if (mod == 1)
	{
		std::cout << "Creating A" << std::endl;
		return (new A);
	}
	else if (mod == 2)
	{
		std::cout << "Creating B" << std::endl;
		return (new B);
	}
	std::cout << "Creating C" << std::endl;
	return (new C);
}

//With pointers, dynamic cast doesn't throw upon failure, only return nullptr

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) 
		std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) 
		std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
		std::cout << "C" << std::endl;
    else 
		std::cout << "Unknown type" << std::endl;
}

// with reference, dynamic cast throws upon failures, so needs a try-catch.
void identify(Base& p) {
    try 
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } 
	catch (...) 
	{
    	try 
		{
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } 
		catch (...) 
		{
            try 
			{
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } 
			catch (...) 
			{
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main(void)
{
	try 
	{

		Base *obj = generate();

		std::cout << "\nIdentifying object with pointer:\n";
		identify(obj);
	
		std::cout << "\n\nIdentifying object with reference:\n";
		identify(*obj);

		delete obj;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what();
	}
	return 0;
}