#pragma once

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat() override;

		WrongCat& operator=(const WrongCat& other);

		void makeSound() const;
};