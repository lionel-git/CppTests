#pragma once

#include <string>
#include <vector>

// Just a wrapper around vector<string> to test aliasing and intellisense behavior with templates and type aliases
template<size_t Index, typename U = std::string>
class VectorWrapper
{
public:

    void add(const U& value)
    {
        data_.push_back(value);
    }

private:
    std::vector<U> data_{};
};

using PalFormula = VectorWrapper<0>;
using FTEvent = VectorWrapper<1>;
using VecInt = VectorWrapper<2, int>;
