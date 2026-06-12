#include <iostream>
#include <string>
#include <vector>

#include <typeinfo>
#include <cstdlib>
#include <memory>

#if !defined(_WIN32)
#include <cxxabi.h>
#endif

class Toto
{
};

std::string demangle(const char* name) 
{
#if !defined(_WIN32)
    int status = -1;
    std::unique_ptr<char, void(*)(void*)> res { abi::__cxa_demangle(name, NULL, NULL, &status), std::free };
    return (status==0) ? res.get() : name ;
#else
    return name;
#endif
}

template <typename T>
void showName()
{
  std::cout << typeid(T).name() << " => " << demangle(typeid(T).name()) << std::endl;
}


void test_demangle()
{
    showName<int>();
    showName<Toto>();
    showName<std::vector<Toto>>();
}
