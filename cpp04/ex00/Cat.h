#pragma once

#include "Animal.h"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat() override;

		Cat& operator=(const Cat& other);

		void makeSound() const override;
};