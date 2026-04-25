#include <vector>
#include "mytype.h"

size_t test_alias()
{
   

    mytype::MyType v = { 1, 2, 3, 4, 5 };

    mytype2::MyType2 vp = { 1, 2, 3, 4, 5 };

    std::vector<int> v2 = v; // This should work since MyType is an alias for std::vector<int>

    std::vector<int> v3 = vp; // This should work since MyType2 is an alias for std::vector<int>

    return v2.size() + v3.size(); // Should return 10, as v2 has 5 elements and v3 has 5 elements

}