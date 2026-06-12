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

extern void test_static_init();

extern void test_copy_ctor();

extern void test_bad_alloc();

extern void test_template();

extern void test_enum_iter();

extern void test_ope_egal();

namespace ns_test_dyn_cast
{
    extern void test_dyn_cast();

}

extern void test_demangle();

int main(int argc, char **argv)
{
    try
    {
        test_demangle(); return 0;

        ns_test_dyn_cast::test_dyn_cast(); return 0;

        test_ope_egal(); return 0;

        test_enum_iter(); return 0;

        test_template(); return 0;

        test_bad_alloc(); return 0;

        test_copy_ctor(); return 0;

        test_static_init(); return 0;

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
