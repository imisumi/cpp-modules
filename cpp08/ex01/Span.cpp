#include "Span.h"

#include <algorithm>
#include <limits>

Span::Span(uint32_t N)
{
	m_Data.reserve(N);
}

size_t Span::size() const
{
	return m_Data.size();
}

size_t Span::capacity() const
{
	return m_Data.capacity();
}

void Span::addNumber(int number)
{
	if (m_Data.size() < m_Data.capacity())
	{
		m_Data.emplace_back(number);
		m_Data.back();
		return;
	}
	throw std::runtime_error("Span is full");
}

int Span::shortestSpan() const
{
	if (m_Data.size() < 2)
		throw std::runtime_error("Not enough elements to calculate span, need at least 2");

	std::vector<int> sorted = m_Data;
	std::sort(sorted.begin(), sorted.end());

	int min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() const
{
	if (m_Data.size() < 2)
		throw std::runtime_error("Not enough elements to calculate span, need at least 2");

	std::vector<int> sorted = m_Data;
	std::sort(sorted.begin(), sorted.end());

	return sorted.back() - sorted.front();
}
