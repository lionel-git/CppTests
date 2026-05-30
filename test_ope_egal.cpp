#include <iostream>


class IBase
{
public:
    virtual ~IBase() = default;
    virtual void assign(const IBase& other) = 0;
};


class Derived : public IBase
{
public:

    void assign(const IBase& other) override
    {
        const auto* derived_other = dynamic_cast<const Derived*>(&other);
        if (derived_other)
        {
            // Perform the assignment logic specific to Derived
            // For demonstration, we just print a message
            std::cout << "OK" << std::endl;
        }
        else
        {
            std::cout << "Bad: " << typeid(*this).name()  << ".assign(" << typeid(other).name() << std::endl;
        }
        std::cout << "Derived::assign called" << std::endl;
    }
};


class Derived2 : public IBase
{
public:

    void assign(const IBase& other) override
    {
        const auto* derived_other = dynamic_cast<const Derived2*>(&other);
        if (derived_other)
        {
            // Perform the assignment logic specific to Derived2
            // For demonstration, we just print a message
            std::cout << "OK" << std::endl;
        }
        else
        {
            std::cout << "Bad: " << typeid(other).name() << std::endl;
        }
        std::cout << "Derived2::assign called" << std::endl;
    }
};

void test_ope_egal()
{
    Derived d1;
    Derived d2;
    d1.assign(d2); // This will call Derived::assign

    Derived2 d3;
    d1.assign(d3); // This will call Derived::assign but print "Bad"

}