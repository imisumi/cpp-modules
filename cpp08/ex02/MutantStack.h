#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Default constructor
	MutantStack() = default;

	// Copy constructor
	MutantStack(const MutantStack&) = default;

	// Copy assignment operator
	MutantStack& operator=(const MutantStack&) = default;

	// Move constructor
	MutantStack(MutantStack&&) noexcept = default;

	// Move assignment operator
	MutantStack& operator=(MutantStack&&) noexcept = default;

	// Destructor
	~MutantStack() = default;

	// Iterator
	typedef	typename std::stack<T>::container_type::iterator iterator;
	iterator	begin() { return this->c.begin(); };
	iterator	end() { return this->c.end(); };

	// Const iterator
	typedef	typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator	begin() const { return this->c.begin(); };
	const_iterator	end() const { return this->c.end(); };
};
