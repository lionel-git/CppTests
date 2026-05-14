#include <set>
#include <string>
#include <algorithm>
#include <vector>

#include <iostream>

std::set<std::string> mySet0 = { "Hello", "World0" };

const std::set<std::string>& getMySet1()
{
    static std::set<std::string> mySet1 = { "Hello", "World" };
    return mySet1;
}

const std::set<std::string>& getMySet2()
{
    static std::set<std::string> mySet2 = { "Hello", "World2" };
    return mySet2;
}

const std::set<std::string> mergeSets(const std::vector<std::set<std::string>>& sets)
{
    std::set<std::string> mergedSet;
    for (const auto& s : sets)
        mergedSet.insert(s.begin(), s.end());
    return mergedSet;
}


const std::set<std::string>& getMySet3()
{
    static std::set<std::string> mySet3;
    if (mySet3.empty())
        mySet3 = mergeSets({ mySet0, getMySet1(), getMySet2() });
    return mySet3;
}

void test_static_init()
{
    std::cout << "mySet0: " << mySet0.size() << std::endl;
    std::cout << "mySet1: " << getMySet1().size() << std::endl;
    std::cout << "mySet2: " << getMySet2().size() << std::endl;
    std::cout << "mySet3: " << getMySet3().size() << std::endl;



}