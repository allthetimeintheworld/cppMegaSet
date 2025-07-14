#include "Data.hpp"
#include "Serializer.hpp"
#include <iomanip>
#include <iostream>

int	main(void)
{
	uintptr_t	serialized;
	Data		*deserializedPtr;
	Data		*dynamicData = NULL;
	uintptr_t	serializedDynamic;
	Data		*deserializedDynamic;
	delete		dynamicData;

	std::cout << "=== Serializer Test Program ===" << std::endl;
	// Create a Data object
	Data originalData(42, "Test Object", 3.14159, true);
	std::cout << "\n1. Original Data object:" << std::endl;
	std::cout << "   Address: " << &originalData << std::endl;
	std::cout << "   Content: ";
	originalData.display();
	// Serialize the pointer
	std::cout << "\n2. Serializing the Data pointer..." << std::endl;
	serialized = Serializer::serialize(&originalData);
	std::cout << "   Serialized value: 0x" << std::hex << serialized << std::dec << std::endl;
	// Deserialize back to pointer
	std::cout << "\n3. Deserializing back to pointer..." << std::endl;
	deserializedPtr = Serializer::deserialize(serialized);
	std::cout << "   Deserialized address: " << deserializedPtr << std::endl;
	// Test if pointers are equal
	std::cout << "\n4. Pointer comparison:" << std::endl;
	std::cout << "   Original pointer:    " << &originalData << std::endl;
	std::cout << "   Deserialized pointer: " << deserializedPtr << std::endl;
	std::cout << "   Pointers are equal: " << ((&originalData == deserializedPtr) ? "YES" : "NO") << std::endl;
	// Test if we can access the data through the deserialized pointer
	std::cout << "\n5. Accessing data through deserialized pointer:" << std::endl;
	if (deserializedPtr)
	{
		std::cout << "   Content: ";
		deserializedPtr->display();
	}
	// Additional test: modify data through deserialized pointer
	std::cout << "\n6. Modifying data through deserialized pointer:" << std::endl;
	if (deserializedPtr)
	{
		deserializedPtr->name = "Modified via deserialized pointer";
		deserializedPtr->value = 2.718;
		std::cout << "   Original object after modification: ";
		originalData.display();
		std::cout << "   Via deserialized pointer: ";
		deserializedPtr->display();
	}
	// Test with another Data object
	std::cout << "\n7. Testing with a dynamically allocated Data object:" << std::endl;
	dynamicData = new Data(100, "Dynamic Object", 1.234, false);
	std::cout << "   Dynamic object address: " << dynamicData << std::endl;
	std::cout << "   Dynamic object content: ";
	dynamicData->display();
	serializedDynamic = Serializer::serialize(dynamicData);
	deserializedDynamic = Serializer::deserialize(serializedDynamic);
	std::cout << "   After serialize/deserialize:" << std::endl;
	std::cout << "   Original address:     " << dynamicData << std::endl;
	std::cout << "   Deserialized address: " << deserializedDynamic << std::endl;
	std::cout << "   Addresses match: " << ((dynamicData == deserializedDynamic) ? "YES" : "NO") << std::endl;
	// Clean up
	std::cout << "\n=== Test completed successfully ===" << std::endl;
	return (0);
}
