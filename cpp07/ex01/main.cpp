#include "iter.h"

#include <iostream>

template <typename T>
void square(T &n)
{
	n = n * n;
}

void zero(int &n)
{
	n = 0;
}

int main(void)
{
	// Lambda function
	std::string a[] = {"hello", "world", "foo", "bar"};
	::iter(a, 4, std::function<void(std::string&)>([](std::string &n) { n = "empty"; }));

	for (int i = 0; i < 4; i++)
	{
		std::cout << a[i] << std::endl;
	}

	// Template function
	int b[] = {1, 2, 3, 4, 5};
	::iter(b, 5, square<int>);
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i] << std::endl;
	}

	// Function pointer
	::iter(b, 5, &zero);
	for (int i = 0; i < 5; i++)
	{
		std::cout << b[i] << std::endl;
	}
	return 0;
}