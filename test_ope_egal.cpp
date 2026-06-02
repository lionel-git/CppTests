#include <iostream>
#include <format>

class IBase
{
public:
    virtual ~IBase() = default;
    virtual void assign(const IBase& other) = 0;

    virtual IBase& operator=(const IBase& other) 
    {
        std::cout << "In base " << std::endl;
        return *this; 
    };

    template<typename T>
    const T& as() const
    {
        const auto* casted = dynamic_cast<const T*>(this);
        if (casted)
            return *casted;
        throw std::runtime_error(std::format("Bad cast from '{}' to '{}'", typeid(*this).name(), typeid(T).name()));
    }
};

class Derived : public IBase
{
public:

    void assign(const IBase& other) override
    {
        *this = other.as<Derived>(); // Call the base class assignment operator
        std::cout << "Derived::assign called" << std::endl;
    }

    IBase& operator=(const IBase& other) override
    {
        const auto* derived_other = dynamic_cast<const Derived*>(&other);
        if (derived_other)
        {
            // Perform the assignment logic specific to Derived
            // For demonstration, we just print a message
            std::cout << "OK" << std::endl;
            *this = *derived_other; // Assuming a copy assignment operator is defined
        }
        else
        {
            std::cout << "Bad: " << typeid(*this).name() << ".operator= (" << typeid(other).name() << std::endl;
        }
        std::cout << "Derived::operator= called" << std::endl;
        return *this;
    }

    int a_{};
};

class DeepDerived : public Derived
{
public:

    int c_{};
};

class Derived2 : public IBase
{
public:

    // To be overriden in base class with extra data
    void assign(const IBase& other) override
    {
        *this = other.as<Derived2>(); // Call the base class assignment operator
        std::cout << "Derived2::assign called" << std::endl;
    }


    IBase& operator=(const IBase& other) override
    {
        const auto* derived_other = dynamic_cast<const Derived2*>(&other);
        if (derived_other)
        {
            // Perform the assignment logic specific to Derived2
            // For demonstration, we just print a message
            std::cout << "OK" << std::endl;
            *this = *derived_other; // Assuming a copy assignment operator is defined
        }
        else
        {
            std::cout << "Bad: " << typeid(other).name() << std::endl;
        }
        std::cout << "Derived2::operator= called" << std::endl;
        return *this;
    }
    double b_{};
};

void checkOperatorEgal()
{
    Derived d1;
    d1.a_ = 47;
    Derived d2;
    d2.a_ = 97;
    //d1.assign(d2); // This will call Derived::assign
    const auto& base_d1 = d1;
   // base_d1.operator=(*(const IBase*)&d2);

    Derived2 d3;
    // d1.assign(d3); // This will call Derived::assign but print "Bad"
}


void test_ope_egal()
{
    checkOperatorEgal(); return;

    Derived d1;
    d1.a_ = 47;
    Derived d2;
    d2.a_ = 97;

    std::cout << "=============================="  << std::endl;

    d1.assign(d2); // This will call Derived::assign

    std::cout << "==============================" << std::endl;

    Derived2 d3;
     d1.assign(d3); // This will call Derived::assign but print "Bad"

     std::cout << "==============================" << std::endl;

    Derived* d4 = new DeepDerived();

    std::cout << "name:" << typeid(*d4).name() << std::endl;


}