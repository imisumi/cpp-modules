#include "Point.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main( void )
{
	Point a(-8.0f, -8.0f);
	Point b(7.0f, -6.0f);
	Point c(0.0f, 8.0f);
	// Point intersect = Point(8.0f, 0.0f);
	Point intersect = Point(0.0f, 0.0f);
	const int size = 10;
	for (int y = -size; y <= size; y++)
	{
		for (int x = -size; x <= size; x++)
		{
			if (roundf(intersect.getX()) == x && roundf(intersect.getY()) == y)
			{
				if (bsp(a, b, c, Point(x, y)))
					std::cout << GREEN << "X " << RESET;
				else
					std::cout << RED << "X " << RESET;
			}
			else
			{
				if (bsp(a, b, c, Point(x, y)))
					std::cout << "O ";
				else
					std::cout << ". ";
			}
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}