#pragma once

#include <iostream>
#include <utility>
#include <vector>

class Span
{
public:
	// Default constructor
	Span() = delete;

	// Copy constructor
	Span(const Span&) = default;

	// Copy assignment operator
	Span& operator=(const Span&) = default;

	// Move constructor
	Span(Span&&) noexcept = default;

	// Move assignment operator
	Span& operator=(Span&&) noexcept = default;

	// Destructor
	~Span() = default;

	// Constructor with size
	Span(uint32_t N);

	size_t size() const;
	size_t capacity() const;

	void addNumber(int number);

	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end);

	int shortestSpan() const;
	int longestSpan() const;

private:
	std::vector<int> m_Data;
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
	size_t size = std::distance(begin, end);
	if (m_Data.size() + size > m_Data.capacity())
		throw std::runtime_error("Not enough space to add numbers");
	
	m_Data.insert(m_Data.end(), begin, end);
}
