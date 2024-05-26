#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

#include "Brain.h"

#include <iostream>
#include <memory>

int main()
{
	std::cout << "1. ----------------------------------------------\n";
	{
		Brain brain(brain);
		std::cout << brain.getIdea(0) << std::endl;
		Brain brain2;
		brain2.setIdea(-1, "Idea 0");
		brain2.setIdea(100, "Idea 0");
		brain2.setIdea(0, "Idea 0");
		brain = brain2;
		brain = brain;
		std::cout << brain.getIdea(0) << std::endl;
	}
	std::cout << "2. ----------------------------------------------\n";
	{
		Animal* animals[4];
		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();

		for (int i = 0; i < 4; i++)
		{
			animals[i]->makeSound();
			delete animals[i];
		}
	}
	std::cout << "3. ----------------------------------------------\n";
	{
		Animal* i = new Dog();
		Animal* j = new Cat();

		delete i;
		delete j;
	}
	std::cout << "4. ----------------------------------------------\n";
	{
		Cat one;
		Cat two = one;
		std::cout << "1: " << one.getBrain() << std::endl;
		std::cout << "2: " << two.getBrain() << std::endl;
	}
	std::cout << "4. ----------------------------------------------\n";
	{
		Cat one;
		Cat two;

		one.setIdea(0, "111111");
		two.setIdea(0, "222222");
		std::cout << "1: " << one.getBrain() << " " << one.getIdea(0) << std::endl;
		std::cout << "2: " << two.getBrain() << " " << two.getIdea(0) << std::endl;
		two = one;
		std::cout << "1: " << one.getBrain() << " " << one.getIdea(0) << std::endl;
		std::cout << "2: " << two.getBrain() << " " << two.getIdea(0) << std::endl;
	}
}
