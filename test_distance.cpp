#include <vector>
#include <ranges>
#include <iostream>

void test_distance()
{
    {
        std::vector<int> v = { 1, 2, 3, 4, 5 };

        auto it = std::ranges::find(v, 3);

        size_t dist = std::ranges::distance(v.begin(), it);

        std::cout << dist << std::endl; // Should print 2, as the distance from the beginning to the element '3' is 2
    }
    {
        std::vector<int> v2;
        auto it2 = std::ranges::find(v2, 3);

        size_t dist2 = std::ranges::distance(v2.begin(), it2);

        std::cout << dist2 << std::endl;
    }
}