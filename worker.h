#pragma once

#include <iostream>
#include "sc_list.h"

class Worker
{
public:
    Worker() = default;
    ~Worker() = default;
    void doWork()
    {
        // Simulate work by sleeping for a short duration
        std::cout << "Worker is doing work..." << std::endl;
        intList_.add(42);
        std::cout << intList_.items_[0] << std::endl;
    }

    SCList<int> intList_;
};
