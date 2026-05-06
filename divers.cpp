
#include <string>

void test_split()
{
    std::string str = "Hello,World,This,is,a,test";

    // Passer flag pour fromEnd ou pas

    auto pos =str.find(','); // Should find the first comma and return its position
    if (pos == std::string::npos)
    {
        // No comma found
    }
    else
    {
        std::string firstPart = str.substr(0, pos); // Should extract "Hello"
        std::string secondPart = str.substr(pos + 1); // Should extract "World,This,is,a,test"
    }

    auto pos2 = str.rfind(','); // Should find the last comma, as the string has not been modified
    if (pos2 == std::string::npos)
    {
        // No comma found
    }
    else
    {
        std::string thirdPart = str.substr(0, pos2); // Should extract "Hello,World,This,is,a"
        std::string fourthPart = str.substr(pos2 + 1); // Should extract "test"
    }

}