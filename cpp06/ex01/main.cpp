#include "Serializer.h"

auto main() -> int
{
	Data* data = new Data{"John", 42};
	std::cout << "Name:         " << data->name << ", Age: " << data->age << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "Raw:          " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Name:         " << deserialized->name << ", Age: " << deserialized->age << std::endl;


	std::cout << "Data:         " << data << std::endl;
	std::cout << "Deserialized: " << deserialized << std::endl;

	delete data;
	return 0;
}
