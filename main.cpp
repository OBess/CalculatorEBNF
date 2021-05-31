// C++
#include <iostream>
#include <cassert>
#include <string>

// Custom
#include "include/calculator/calculator.hpp"

int main()
{
	// Main class
	calculator calc;

	// Tests
	assert(calc.compute("2+2") == 4);
	assert(calc.compute("2-2") == 0);
	assert(calc.compute("2*2") == 4);
	assert(calc.compute("2/2") == 1);
	assert(calc.compute("(2+2)*4") == 16);
	assert(calc.compute("-2+2") == 0);
	
	std::cout << "Tests completed" << std::endl;

	//-------------do not write code after this line----------------
	std::cout << std::endl;
   return EXIT_SUCCESS;
}