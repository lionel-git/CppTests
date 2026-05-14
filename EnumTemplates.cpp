#include <string>
#include <iostream>

#include <functional>

enum class Color
{
    Invalid,
    Red,
    Green,
    Blue,
    LastEnum
};

std::string convertEnum(Color color)
{
    switch(color)
    {
        case Color::Invalid:
            return "Invalid";
        case Color::Red:
            return "Red";
        case Color::Green:
            return "Green";
        case Color::Blue:
            return "Blue";
        default:
            return "Unknown";
    }
}

template <Color>
auto getAssociatedObject()
{
    static_assert(false, "This template should be specialized for each Color value.");
}

template<>
auto getAssociatedObject<Color::Red>()
{
    static const std::string redString = "This is Red";
    return redString;
}

template<>
auto getAssociatedObject<Color::Green>()
{
    static const int greenValue = 100;
    return greenValue;
}

template<>
auto getAssociatedObject<Color::Blue>()
{
    static const double blueValue = 234.343;
    return blueValue;
}


void showAllColors()
{
    std::cout << "All Colors:" << std::endl;
    for (int i = static_cast<int>(Color::Invalid) + 1; i < static_cast<int>(Color::LastEnum); ++i)
    {
        Color color = static_cast<Color>(i);
        std::cout << convertEnum(color) << std::endl;
    }
    std::cout << "====" << std::endl;
}

template <typename EnumType>
constexpr EnumType next(EnumType current)
{
    return (EnumType)((int)(current) + 1);
};


template<Color c>
void displayLoop() 
{
    //Execute some code
    std::cout << convertEnum(c) << ": " << getAssociatedObject<c>() << std::endl;
    //Iterate
    displayLoop<next<Color>(c)>();
}
template<>
void displayLoop<Color::LastEnum>() {
}

void displayLoopColors()
{
    displayLoop<next<Color>(Color::Invalid)>();
}

void showObjects()
{
    std::cout << "Associated Objects:" << std::endl;
    displayLoopColors();
    std::cout << "====" << std::endl;
}

void test_load()
{
    Color value = Color::Red;
    // Pb load dynmically the associated object for a given enum value, we need to use a switch or if-else chain, which is not ideal and can lead to maintenance issues as the enum grows.
//    getAssociatedObject<value>();

}

void test_enum()
{
    showAllColors();
    showObjects();
}

