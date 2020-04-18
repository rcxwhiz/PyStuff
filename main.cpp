#include <iostream>
#include <string>
#include <vector>

#include "PyStuff.h"

int main()
{
	std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	PyStuff::vector<int> test2 = PyStuff::vector<int>(test);
	std::cout << test2.contains(-1) << std::endl;
	std::cout << test2.join() << std::endl;
	auto it = test2.begin();
	std::cout << *it << std::endl;

	std::string testString = "my1big1boy1";
	size_t size = test2.size();

	return 0;
}
