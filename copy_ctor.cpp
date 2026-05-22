
#include <iostream>

class A
{
public:
    A() { std::cout << "A ctor" << std::endl; }
    A(const A&) { std::cout << "A Copy ctor" << std::endl; }
};

class B : public A
{
public:
    B() { std::cout << "B ctor" << std::endl; }
    B(const B&) { std::cout << "B Copy ctor" << std::endl; }
};

class C : public A
{
public:
    C() { std::cout << "C ctor" << std::endl; }
    C(const C& rhs): A(rhs) { std::cout << "C Copy ctor" << std::endl; }
};

class D : public A
{
public:
    D() = default;
    D(const D& rhs) = default;
};

class E : public A
{
};

void test_copy_ctor()
{
    std::cout << "==============" << std::endl;
    B b1; // Should call B ctor and A ctor
    std::cout << "---" << std::endl;
    B b2(b1); // Should call B Copy ctor and A Copy ctor
    std::cout << "==============" << std::endl;

    C c1; // Should call C ctor and A ctor
    std::cout << "---" << std::endl;
    C c2(c1); // Should call C Copy ctor and A Copy ctor
    std::cout << "==============" << std::endl;

    D d1; // Should call D ctor and A ctor
    std::cout << "---" << std::endl;
    D d2(d1); // Should call D Copy ctor and A Copy ctor
    std::cout << "==============" << std::endl;

    E e1; // Should call E ctor and A ctor
    std::cout << "---" << std::endl;
    E e2(e1); // Should call E Copy ctor and A Copy ctor
    std::cout << "==============" << std::endl;

    E e3 = e1; // Should call E Copy ctor and A Copy ctor
    E e4;
    std::cout << "Assignment" << std::endl;
    e4 = e1; // Should call E Copy assignment operator and A Copy assignment operator
}
