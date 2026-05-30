#include <iostream>
#include <format>
#include <algorithm>

enum Color
{
    Red,
    Green,
    Blue,
    Last
};

enum Cities
{
    Paris,
    London,
    NewYork,
    LastEnum
};

template <typename EnumType>
EnumType begin()
{
    return static_cast<EnumType>(0);
}

template <typename EnumType>
EnumType end()
{
    static_assert(EnumType::Last > 0, "LastEnum must exist and positive");
    return EnumType::Last;
}

template <>
Cities end<Cities>()
{
    static_assert(Cities::LastEnum > 0, "LastEnum must exist and positive");
    return Cities::LastEnum;
}

template <typename EnumType>
EnumType& operator++(EnumType& e)
{
    static_assert(std::is_enum_v<EnumType>, "EnumType must be an enum");
    if (e >= end<EnumType>())
    {
        throw std::out_of_range(std::format("Enum '{}' value out of range: {}", typeid(EnumType).name(), static_cast<size_t>(e)));
    }

    const size_t v = static_cast<size_t>(e);
    e = static_cast<EnumType>(v + 1);
    return e;
}

void print(Color c)
{
    std::cout << "Color: " << static_cast<size_t>(c) << std::endl;
}

void test_ok()
{
    for (auto c = begin<Color>(); c < end<Color>(); ++c)
        print(c);
}

void test_bad()
{
    for (auto c = begin<Color>(); c < end<Color>() + 1; ++c)
        print(c);
}

void test_cities()
{
    for (auto c = begin<Cities>(); c < end<Cities>(); ++c)
        std::cout << "City: " << static_cast<size_t>(c) << std::endl;
}

void test_enum_iter()
{
    test_ok();
    try
    {
        test_bad();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exc: " << ex.what() << std::endl;
    }
    test_cities();

//    std::for_each(begin<Color>(), end<Color>(), &print);
 //   std::for_each(Color::Red, Color::Last, &print);

}
