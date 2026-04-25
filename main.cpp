#include <iostream>

extern void test_map_wrapper();
extern void test_distance();


extern size_t test_alias();

namespace tester
{
    extern size_t test_alias2();
}

int main(int argc, char **argv)
{
    try
    {
        //test_map_wrapper();
        test_distance();
        size_t alias_result = tester::test_alias2();
        size_t alias_result2 = test_alias();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
