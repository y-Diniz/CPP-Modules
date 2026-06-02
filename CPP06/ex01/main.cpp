#include "Serialize.hpp"
#include <iostream>

int main() {

	Data *d = new Data;
	std::cout << "Data address: " << d << std::endl;
	uintptr_t i = Serialize::serialize(d);
	std::cout << "Data serialized: " << i << std::endl;
	d = Serialize::deserialize(i);
	std::cout << "Data deserialized: " << d << std::endl;

	delete d;

	return 0;
}