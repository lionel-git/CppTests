#include <iostream>

void func_with_except() noexcept(false)
{
	std::cout << "funcfunc_with_except" << std::endl;
	throw std::runtime_error("error in func_with_except");
}

void test_function() noexcept
{
	std::cout << "test_function" << std::endl;
	func_with_except();
}

void test_noex()
{
	test_function();
	std::cout << "noex.cpp" << std::endl;
}
