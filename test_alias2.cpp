#include <vector>
// If alias is defined, instellisense display all std::vector<int> with MyType
// but if alias is not defined, it display all std::vector<int> with std::vector<int>
#include "mytype.h"

#include "vectorString.h"

namespace tester
{
    size_t test_alias2()
    {


        std::vector<int> v = { 1, 2, 3, 4, 5 };

        std::vector<int> v2 = v;

        std::vector<int> v3;

        return v2.size() + v3.size();

    }

    size_t test_alias3()
    {
       PalFormula f1;
       FTEvent e2;
       VecInt v1;
       std::vector<int> v3;

       f1.add("test");
       e2.add("event");
       v1.add(42);
       v3.push_back(34);

        return 0;
    }
}

