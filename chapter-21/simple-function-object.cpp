#include <iostream>
#include "libfunc-object.h"
#include "extern-func.h"

int main()
{
	int a = 42;	
	Composition<int, int> fg(f, g);
	Composition<int, int> fgf(fg, f);
	Composition<int, int> fgfg(fgf, g);
	fg(a);
	std::cout << "\n segment \n" << std::endl;
	fgf(a);
	std::cout << "\n segment \n" << std::endl;
	fgfg(a);
	return 0;
}