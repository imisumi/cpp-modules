#pragma once

#include <iostream>
#include <utility>

struct Data
{
	std::string name;
	int age;
};

class Serializer
{
public:
	// Default constructor
	Serializer() = delete;

	// Copy constructor
	Serializer(const Serializer&) = delete;

	// Copy assignment operator
	Serializer& operator=(const Serializer&) = delete;

	// Move constructor
	Serializer(Serializer&&) noexcept = delete;

	// Move assignment operator
	Serializer& operator=(Serializer&&) noexcept = delete;

	// Destructor
	~Serializer() = delete;

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:

};
