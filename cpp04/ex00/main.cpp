#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

#include <iostream>
#include <memory>

int main()
{
	std::cout << "1. ----------------------------------------------\n";
	{
		std::unique_ptr<Animal> animal = std::make_unique<Animal>(Animal());
		std::cout << "Animal address: " << animal.get() << std::endl;
		std::unique_ptr<Animal> Animal2 = std::move(animal);
		std::cout << "Animal address: " << animal.get() << std::endl;
		std::cout << "Animal2 address: " << Animal2.get() << std::endl;
	}
	std::cout << "2. ----------------------------------------------\n";
	{
		std::unique_ptr<Animal> animal = std::make_unique<Animal>();
		std::unique_ptr<Animal> cat = std::make_unique<Cat>();
		std::unique_ptr<Animal> dog = std::make_unique<Dog>();
		std::cout << animal->getType() << " - ";
		animal->makeSound();
		std::cout << cat->getType() << " - ";
		cat->makeSound();
		std::cout << dog->getType() << " - ";
		dog->makeSound();
	}
	std::cout << "3. ----------------------------------------------\n";
	{
		std::unique_ptr<WrongAnimal> animal = std::make_unique<WrongAnimal>();
		std::unique_ptr<WrongAnimal> cat = std::make_unique<WrongCat>();
		std::cout << animal->getType() << " - ";
		animal->makeSound();
		std::cout << cat->getType() << " - ";
		cat->makeSound();
	}
}
