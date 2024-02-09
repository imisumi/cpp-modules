#include "Fixed.h"
//reader for rand
#include <cstdlib>
#include <limits>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	a / Fixed(0);

	std::cout << std::endl;

	float	random;
	float	random2;
	int		i;
	srand(static_cast<unsigned int>(time(nullptr)));
	for (i = 0; i < 1000; i++)
	{
		random = static_cast<float>(rand()) / (RAND_MAX / 8);
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if ((random > random2) != (Fixed(random) > Fixed(random2))){
			std::cout << "KO " << random << " " << random2 << " >" << std::endl;
			break ;
		}
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if ((random < random2) != (Fixed(random) < Fixed(random2))){
			std::cout << "KO " << random << " " << random2 << " <" << std::endl;
			break ;
		}
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if ((random >= random2) != (Fixed(random) >= Fixed(random2))){
			std::cout << "KO " << random << " " << random2 << " >=" << std::endl;
			break ;
		}
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if ((random <= random2) != (Fixed(random) <= Fixed(random2))){
			std::cout << "KO " << random << " " << random2 << " <=" << std::endl;
			break ;
		}
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if ((random == random2) != (Fixed(random) == Fixed(random2))){
			std::cout << "KO " << random << " " << random2 << " ==" << std::endl;
			break ;
		}
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if ((random != random2) != (Fixed(random) != Fixed(random2))){
			std::cout << "KO " << random << " " << random2 << " !=" << std::endl;
			break ;
		}
		/*
		min - max
		*/
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if (std::min(Fixed(random).getRawBits(), Fixed(random2).getRawBits()) != Fixed::min(Fixed(random), Fixed(random2)).getRawBits()){
			std::cout << "KO " << random << " " << random2 << " min" << std::endl;
			break ;
		}
		random2 = static_cast<float>(rand()) / (RAND_MAX / 8);
		if (std::max(Fixed(random).getRawBits(), Fixed(random2).getRawBits()) != Fixed::max(Fixed(random), Fixed(random2)).getRawBits()){
			std::cout << "KO " << random << " " << random2 << " max" << std::endl;
			break ;
		}
	}
	if (i != 1000)
		std::cout << "Due to floating-point conversion inaccuracies the numbers " 
			<< random << " and " << random2 
			<< " have the same binary representations " 
			<< Fixed(random).getRawBits() << " and " << Fixed(random2).getRawBits() << std::endl;

	return EXIT_SUCCESS;
}