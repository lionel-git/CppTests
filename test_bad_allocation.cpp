#include <stdexcept>
#include <iostream>

void test_bad_alloc()
{
    try
    {
        unsigned long long N = 100'000'000'000;
        const auto ptr = std::make_unique<int[]>(N);
        std::cout << "Memory allocated successfully for " << N << " integers." << std::endl;
        ptr[N-5] = 42; // Use the allocated memory

    }
    catch (const std::bad_alloc& e)
    {
        std::cout << "Caught bad_alloc: " << e.what() << std::endl;
    }
}
