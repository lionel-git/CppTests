#include <iostream>

extern void test_map_wrapper();
extern void test_distance();


extern size_t test_alias();

namespace tester
{
    extern size_t test_alias2();
    extern size_t test_alias3();
}

extern  void test_operator();
extern void test_enum();
int main(int argc, char **argv)
{
    try
    {
        test_enum(); return 0;

        test_operator(); return 0;

        //test_map_wrapper();
        test_distance();
        size_t alias_result2 = tester::test_alias2();
        size_t alias_result3 = tester::test_alias3();
        size_t alias_result4 = test_alias();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
