#include <iostream>

struct B
{
    B() { std::cout << "B Default constructor called" << std::endl; }
    B(int b) : b_(b) { std::cout << "B Parameterized constructor called" << std::endl; }
    ~B() { std::cout << "B Destructor called" << std::endl; }
    B (const B& rhs)
    {
        std::cout << "B Copy constructor called" << std::endl;
        b_ = rhs.b_;
    }

    int b_{ 0 };
};

struct A
{
    A() {}
    A(const A& rhs)
    {
        std::cout << "A Copy constructor called" << std::endl;
        a_ = rhs.a_;
        b_ = std::make_unique<B>(*rhs.b_);
    }
    ~A() { std::cout << "A Destructor called" << std::endl; }
    A& operator=(const A& rhs)
    {
        if (this != &rhs)
        {
            new (this) A(rhs);
        }
        std::cout << "A Assignment operator called" << std::endl;
        return *this;
    }

    int a_{ 0 };
    std::unique_ptr<B> b_{};
};


void test_operator()
{
    A a1;
    a1.a_ = 42;
    a1.b_ = std::make_unique<B>(41);
    A a2 = a1; // This should call the copy constructor and print "Copy constructor called"
    A a3;
    std::cout << "Assigning a1 to a3" << std::endl;
    a3 = a1; // This should call the assignment operator and print "Assignment operator called"
    std::cout << "After assigning a1 to a3" << std::endl;

}
