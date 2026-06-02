#include "Serialize.hpp"
#include <iostream>

int main() {

	Data data;
	Data *ptr = &data;
	std::cout << "Data address: " << ptr << std::endl;

	uintptr_t raw = Serialize::serialize(ptr);
	std::cout << "Data serialized: " << raw << std::endl;

	Data *ptr2 = Serialize::deserialize(raw);
	std::cout << "Data deserialized: " << ptr2 << std::endl;

	std::cout << "ptr == ptr2: " << (ptr == ptr2 ? 1 : 0) << std::endl ;

	return 0;
}