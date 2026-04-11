#include <iostream>

extern void test_map_wrapper();


int main(int argc, char **argv)
{
    try
    {
        test_map_wrapper();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}
