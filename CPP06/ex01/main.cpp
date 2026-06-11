#include "Serializer.hpp"
#include <iostream>

int main() {

	Data data;
	Data *ptr = &data;
	std::cout << "Data address: " << ptr << std::endl;

	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "Data Serializerd: " << raw << std::endl;

	Data *ptr2 = Serializer::deserialize(raw);
	std::cout << "Data deSerializerd: " << ptr2 << std::endl;

	std::cout << "ptr == ptr2: " << (ptr == ptr2 ? 1 : 0) << std::endl ;

	return 0;
}