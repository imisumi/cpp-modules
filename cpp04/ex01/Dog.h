#pragma once

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		~Dog() override;

		Dog& operator=(const Dog& other);

		void makeSound() const override;

		Brain* getBrain() const;

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;

	private:
		Brain* m_Brain = nullptr;
};