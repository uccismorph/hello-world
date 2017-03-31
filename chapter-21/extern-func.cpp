#include "extern-func.h"

#include <iostream>

int f(int a)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return a;
}
int g(int a)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return a;
}