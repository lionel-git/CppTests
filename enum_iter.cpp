#include <iostream>
#include <format>

enum Color
{
    Red,
    Green,
    Blue,
    Last
};

template <typename EnumType>
EnumType& operator++(EnumType& e)
{
    static_assert(std::is_enum_v<EnumType>, "EnumType must be an enum");
    static_assert(EnumType::Last > 0, "Last must exist and positive");
    if (e >= EnumType::Last)
    {
        throw std::out_of_range(std::format("Enum '{}' value out of range: {}", typeid(EnumType).name(), static_cast<size_t>(e)));
    }
    const size_t v = static_cast<size_t>(e);
    e = static_cast<EnumType>(v + 1);
    return e;
}

template <typename EnumType>
EnumType first()
{
    return static_cast<EnumType>(0);
}

void test_enum_iter()
{
    for (auto c = first<Color>(); c < Color::Last; ++c)
    {        
        std::cout << "Color: " << static_cast<size_t>(c) << std::endl;
    }
}
