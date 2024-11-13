#pragma once

#include <iostream>

// template class
template <typename T>
class Array
{
public:
	// Default constructor
	Array() = default;

	// Constructor with size
	Array(uint32_t n);

	// Copy constructor
	Array(const Array &other);

	// Copy assignment operator
	Array& operator=(const Array &other);

	// Move constructor
	Array(Array &&other) noexcept;

	// Move assignment operator
	Array& operator=(Array &&other) noexcept;

	// Destructor
	~Array();

	// Index operator
	T& operator[](uint32_t index);

	// Iterators
	T* begin() { return m_Data; }
	T* end() { return m_Data + m_Size; }
	const T* begin() const { return m_Data; }
	const T* end() const { return m_Data + m_Size; }

	uint32_t size() const { return m_Size; }

private:
	T* m_Data = nullptr;
	uint32_t m_Size = 0;
};

// Constructor with size
template <typename T>
Array<T>::Array(uint32_t n)
	: m_Size(n)
{
	m_Data = new T[n];
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &other)
{
	m_Size = other.m_Size;
	m_Data = new T[m_Size];
	for (uint32_t i = 0; i < m_Size; i++)
	{
		m_Data[i] = other.m_Data[i];
	}
}

// Copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;

	if (m_Data)
		delete[] m_Data;

	m_Size = other.m_Size;
	m_Data = new T[m_Size];
	for (uint32_t i = 0; i < m_Size; i++)
	{
		m_Data[i] = other.m_Data[i];
	}
	return *this;
}

// Move constructor
template <typename T>
Array<T>::Array(Array &&other) noexcept
{
	m_Size = other.m_Size;
	m_Data = other.m_Data;
	other.m_Size = 0;
	other.m_Data = nullptr;
}

// Move assignment operator
template <typename T>
Array<T>& Array<T>::operator=(Array &&other) noexcept
{
	if (this == &other)
		return *this;

	if (m_Data)
		delete[] m_Data;

	m_Size = other.m_Size;
	m_Data = other.m_Data;
	other.m_Size = 0;
	other.m_Data = nullptr;
	return *this;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	if (m_Data)
		delete[] m_Data;
	m_Data = nullptr;
}

// Index operator
template <typename T>
T& Array<T>::operator[](uint32_t index)
{
	if (index >= m_Size)
	{
		throw std::out_of_range("Index out of range");
	}
	return m_Data[index];
}
