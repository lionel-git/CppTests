#include <iostream>

#include <map>

namespace ns_test_dyn_cast
{
    struct A
    {
        virtual ~A() = default;
        virtual void show() { std::cout << "A" << std::endl; }
    };

    struct B : public A
    {
    };

    struct C : public A
    {

    };

    struct D : public B
    {
    };

    template<typename T, typename U>
    class Tata;
    
    class Tata0;

    using Toto1 = std::string;
    using Toto2 = Tata0;
    using Toto3 = std::map<std::string, Tata<int, int>>;

    void test_dyn_cast()
    {
        A* a = new A();
        B b;

        A& ref = b;

        B* ptr = dynamic_cast<B*>(a); // This will return nullptr since 'a' is not of type 'B'

        B& ref2 = dynamic_cast<B&>(ref);

        std::cout << "ref2 is of type B" << std::endl;
        B& ref3 = dynamic_cast<B&>(*a); // 




    }
}
