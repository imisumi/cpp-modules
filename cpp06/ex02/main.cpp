#include "A.h"
#include "B.h"
#include "C.h"

Base* generate()
{
	int random = rand() % 3;
	if (random == 0)
	{
		return new A();
	}
	else if (random == 1)
	{
		return new B();
	}
	else
	{
		return new C();
	}
}

void identify(Base* p)
{
	// if (dynamic_cast<A*>(p))
	if (A* a = dynamic_cast<A*>(p))
	{
		std::cout << "A    ptr:  " << a << std::endl;
	}
	else if (B* b = dynamic_cast<B*>(p))
	{
		std::cout << "B    ptr:  " << b << std::endl;
	}
	else if (C* c = dynamic_cast<C*>(p))
	{
		std::cout << "C    ptr:  " << c << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A    ref:  " << &a << std::endl;
	}
	catch (std::bad_cast& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B    ref:  " << &b << std::endl;
	}
	catch (std::bad_cast& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C    ref:  " << &c << std::endl;
	}
	catch (std::bad_cast& e)
	{
	}
}

void run()
{
	Base* base = generate();
	std::cout << "Base addr: " << base << std::endl;
	identify(base);
	identify(*base);
	delete base;
}

auto main() -> int
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		std::cout << "-------------------------" << std::endl;
		run();
	}
	return 0;
}
