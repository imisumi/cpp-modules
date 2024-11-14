#include "MutantStack.h"

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m\n"

#include <iostream>
#include <any>
#include <memory>
#include <array>
#include <vector>
#include <list>
#include <stack>

template <typename Container, typename T>
requires requires(Container c, T value) { c.emplace_back(value); }
void addBack(Container& container, T&& value)
{
	container.emplace_back(std::forward<T>(value));
}


template <typename Container, typename T>
requires requires(Container c, T value) { c.push(value); }
void addBack(Container& container, const T& value)
{
	container.push(value);
}

template <typename Container>
requires requires(Container c) { c.pop_back(); }
void removeBack(Container& container)
{
	if (container.size() == 0)
		return;
	container.pop_back();
}

template <typename Container>
requires requires(Container c) { c.pop(); }
void removeBack(Container& container)
{
	if (container.size() == 0)
		return;
	container.pop();
}

template <typename Container>
requires requires(Container c) { c.size(); }
void size(Container& container)
{
	container.size();
}


void addBack(std::vector<std::any>& containers, int value)
{
	for (auto& c : containers)
	{
		if (c.type() == typeid(std::vector<int>))
		{
			auto& vec = std::any_cast<std::vector<int>&>(c);
			addBack(vec, value);
		}
		else if (c.type() == typeid(std::list<int>))
		{
			auto& lst = std::any_cast<std::list<int>&>(c);
			addBack(lst, value);
		}
		else if (c.type() == typeid(MutantStack<int>))
		{
			auto& stk = std::any_cast<MutantStack<int>&>(c);
			addBack(stk, value);
		}
		else if (c.type() == typeid(std::deque<int>))
		{
			auto& deq = std::any_cast<std::deque<int>&>(c);
			addBack(deq, value);
		}
	}
}

void removeBack(std::vector<std::any>& containers)
{
	for (auto& c : containers)
	{
		if (c.type() == typeid(std::vector<int>))
		{
			auto& vec = std::any_cast<std::vector<int>&>(c);
			removeBack(vec);
		}
		else if (c.type() == typeid(std::list<int>))
		{
			auto& lst = std::any_cast<std::list<int>&>(c);
			removeBack(lst);
		}
		else if (c.type() == typeid(MutantStack<int>))
		{
			auto& stk = std::any_cast<MutantStack<int>&>(c);
			removeBack(stk);
		}
		else if (c.type() == typeid(std::deque<int>))
		{
			auto& deq = std::any_cast<std::deque<int>&>(c);
			removeBack(deq);
		}
	}
}

void printContainerElements(const std::vector<std::any>& containers)
{
	for (const auto& c : containers)
	{
		if (c.type() == typeid(std::vector<int>))
		{
			const auto& vec = std::any_cast<std::vector<int>>(c);
			for (const auto& elem : vec)
				std::cout << elem << ' ';
		}
		else if (c.type() == typeid(std::list<int>))
		{
			const auto& lst = std::any_cast<std::list<int>>(c);
			for (const auto& elem : lst)
				std::cout << elem << ' ';
		}
		else if (c.type() == typeid(MutantStack<int>))
		{
			const auto& stk = std::any_cast<MutantStack<int>>(c);
			for (const auto& elem : stk)
				std::cout << elem << ' ';
		}
		else if (c.type() == typeid(std::deque<int>))
		{
			const auto& deq = std::any_cast<std::deque<int>>(c);
			for (const auto& elem : deq)
				std::cout << elem << ' ';
		}
		std::cout << '\n';
	}
}

void printContainerSize(const std::vector<std::any>& containers)
{
	for (const auto& c : containers)
	{
		if (c.type() == typeid(std::vector<int>))
		{
			const auto& vec = std::any_cast<std::vector<int>>(c);
			std::cout << vec.size() << std::endl;
		}
		else if (c.type() == typeid(std::list<int>))
		{
			const auto& lst = std::any_cast<std::list<int>>(c);
			std::cout << lst.size() << std::endl;
		}
		else if (c.type() == typeid(MutantStack<int>))
		{
			const auto& stk = std::any_cast<MutantStack<int>>(c);
			std::cout << stk.size() << std::endl;
		}
		else if (c.type() == typeid(std::deque<int>))
		{
			const auto& deq = std::any_cast<std::deque<int>>(c);
			std::cout << deq.size() << std::endl;
		}
	}
}

int main()
{
	std::vector<std::any> vec;
	vec.push_back(std::vector<int>());
	vec.push_back(std::list<int>());
	vec.push_back(MutantStack<int>());
	vec.push_back(std::deque<int>());

	for (int i = 0; i < 10; i++)
		addBack(vec, i);

	std::cout << GREEN << "Elements of containers:" << RESET;
	printContainerElements(vec);
	std::cout << CYAN << "Size of containers:" << RESET;
	printContainerSize(vec);
	
	
	for (int i = 0; i < 5; i++)
		removeBack(vec);

	std::cout << GREEN << "Elements of containers:" << RESET;
	printContainerElements(vec);
	std::cout << CYAN << "Size of containers:" << RESET;
	printContainerSize(vec);

	for (int i = 0; i < 999; i++)
		removeBack(vec);

	std::cout << GREEN << "Elements of containers:" << RESET;
	printContainerElements(vec);
	std::cout << CYAN << "Size of containers:" << RESET;
	printContainerSize(vec);
}
