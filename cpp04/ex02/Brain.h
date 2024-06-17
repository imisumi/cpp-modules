#pragma once

#include <iostream>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m\n"

#define MAX_IDEAS 100

class Brain
{
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain& operator=(const Brain& other);

	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;

private:
	std::string m_Ideas[MAX_IDEAS];
};