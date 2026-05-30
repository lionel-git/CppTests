#pragma once
#include <vector>

template <typename T>
class SCList
{
public:
    SCList() = default;
    ~SCList() = default;
    void add(const T& item)
    {
        items_.push_back(item);
    }


    std::vector<T> items_{};
};