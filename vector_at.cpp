#include <iostream>
#include <vector>

void test_vector_at() {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::cout << "Accessing element at index 2: " << vec.at(2) << std::endl;
	std::cout << "Accessing element at index 10: " << vec.at(10) << std::endl; // This will throw an exception


}
