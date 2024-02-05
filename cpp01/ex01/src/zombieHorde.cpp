#include "Zombie.h"

// Zombie* zombieHorde(int N, std::string name)
// {
// 	if (N <= 0)
// 		return (nullptr);
// 	Zombie* horde = new Zombie[N];
// 	for (int i = 0; i < N; i++)
// 		horde[i].setName(name + std::to_string(i));
// 	return (horde);
// }

// Zombie* zombieHorde(int N, std::string name)
// {
// 	if (N <= 0)
// 		return (nullptr);
// 	try
// 	{
// 		Zombie* horde = new Zombie[N];
// 		for (int i = 0; i < N; i++)
// 			horde[i].setName(name + std::to_string(i));
// 		return horde;
// 	}
// 	catch (std::bad_alloc& e)
// 	{
// 		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
// 		return nullptr;
// 	}
// }

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;
	try
	{
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			try
			{
				horde[i].setName(name + std::to_string(i));
			}
			catch (const std::exception& e)
			{
				std::cerr << "String concatenation failed: " << e.what() << std::endl;
				delete[] horde;
				return nullptr;
			}
		}
		return horde;
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return nullptr;
	}
}
