#include <vector>
#include "mytype.h"

size_t test_alias()
{
   

    mytype::MyType v = { 1, 2, 3, 4, 5 };

    std::vector<int> v2 = v; // This should work since MyType is an alias for std::vector<int>

    std::vector<int> v3;

    return v2.size() + v3.size(); // Should return 5, as v2 has 5 elements and v3 is empty

}