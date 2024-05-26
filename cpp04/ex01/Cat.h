#pragma once

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat() override;

		Cat& operator=(const Cat& other);

		void makeSound() const override;

		Brain* getBrain() const;

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;

	private:
		Brain* m_Brain = nullptr;
};