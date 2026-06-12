#include <iostream>

class Toto
{
};


template <typename T>
void showName()
{
    std::cout << typeid(T).name() << std::endl;
}


void test_demangle()
{
    showName<int>();
    showName<Toto>();
    // This function is intentionally left empty to demonstrate the use of demangling.
    // In a real scenario, you would have some code here that generates mangled names,
    // and you would use a demangling library to convert them back to human-readable form.
}
