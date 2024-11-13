#pragma once

#include <type_traits>

template <typename T>
void swap(T &a, T &b)
{
	// static_assert(std::is_copy_constructible<T>::value, "Type T must be copy constructible");
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b)
{
	// static_assert(std::is_copy_constructible<T>::value, "Type T must be copy constructible");
	return a < b ? a : b;
}

template <typename T>
T max(T a, T b)
{
	// static_assert(std::is_copy_constructible<T>::value, "Type T must be copy constructible");
	return a > b ? a : b;
}