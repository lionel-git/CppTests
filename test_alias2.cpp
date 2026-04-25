#include <vector>
// If alias is defined, instellisense display all std::vector<int> with MyType
// but if alias is not defined, it display all std::vector<int> with std::vector<int>
#include "mytype.h"

namespace tester
{
    size_t test_alias2()
    {


        std::vector<int> v = { 1, 2, 3, 4, 5 };

        std::vector<int> v2 = v;

        std::vector<int> v3;

        return v2.size() + v3.size();

    }
}