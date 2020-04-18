#include <iostream>
#include <string>
#include <vector>

#include "PyStuff.h"

int main()
{
	std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	PyStuff::vector<int> test2 = PyStuff::vector<int>(test);
	std::cout << test2.contains(-1) << std::endl;
	test2 * 2;
	std::cout << (test2 * 2).size() << std::endl;

	return 0;
}
