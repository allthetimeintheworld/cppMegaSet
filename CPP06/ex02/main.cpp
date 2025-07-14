#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "Functions.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "=== Dynamic Type Identification Test ===" << std::endl;

	std::cout << "\n1. Testing generate() function:" << std::endl;

	// Generate multiple objects and test identification
	for (int i = 0; i < 6; i++)
	{
		std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;

		Base *obj = generate();

		std::cout << "Identify via pointer: ";
		identify(obj);

		std::cout << "Identify via reference: ";
		identify(*obj);

		delete obj;
	}

	std::cout << "\n2. Testing with specific types:" << std::endl;

	// Test with known types
	std::cout << "\n--- Creating A object ---" << std::endl;
	Base *a = new A();
	std::cout << "Pointer identification: ";
	identify(a);
	std::cout << "Reference identification: ";
	identify(*a);
	delete a;

	std::cout << "\n--- Creating B object ---" << std::endl;
	Base *b = new B();
	std::cout << "Pointer identification: ";
	identify(b);
	std::cout << "Reference identification: ";
	identify(*b);
	delete b;

	std::cout << "\n--- Creating C object ---" << std::endl;
	Base *c = new C();
	std::cout << "Pointer identification: ";
	identify(c);
	std::cout << "Reference identification: ";
	identify(*c);
	delete c;

	std::cout << "\n3. Testing edge cases:" << std::endl;

	// Test with NULL pointer
	std::cout << "\n--- Testing NULL pointer ---" << std::endl;
	Base *null_ptr = NULL;
	std::cout << "NULL pointer identification: ";
	identify(null_ptr);

	std::cout << "\n=== All tests completed ===" << std::endl;

	return (0);
}