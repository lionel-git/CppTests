#include <iostream>
#include <map>
#include <memory>

// Wraps a map of unique pointers to objects of type T
// With auto initialization of the unique pointers when accessed via operator[]
template<typename T>
class MapWrapper
{
public:
    MapWrapper(bool initOnNullPtr) : initOnNullPtr_(initOnNullPtr) {}

    std::unique_ptr<T>& operator[](const std::string& key)
    {
        auto it = map_.find(key);
        if (it == map_.end())
        {
            map_[key] = std::make_unique<T>();
            it = map_.find(key);
        }
        if (it->second == nullptr && initOnNullPtr_)
            it->second = std::make_unique<T>();
        return it->second;
    }

    bool isEmpty(const std::string& key) const
    {
        auto it = map_.find(key);
        return it == map_.end() || it->second == nullptr;
    }

private:
    std::map<std::string, std::unique_ptr<T>> map_;
    bool initOnNullPtr_{ false };
};

struct TestObject
{
    void show() const
    {
        std::cout << "TestObject at address: " << this << std::endl;
    }
};

void test_map_wrapper_init(bool init_value)
{
    std::cout << "Testing map wrapper init=" << init_value << std::endl;
    MapWrapper<TestObject> wrapper(init_value);

    const std::string mykey = "toto";
    std::cout << "isempty: " << wrapper.isEmpty(mykey) << std::endl; // Should print false, as the key exists and is not empty
    wrapper[mykey]->show(); // Should auto-initialize and print the address of the TestObject
    auto p1 = std::move(wrapper[mykey]);
    std::cout << "isempty: " << wrapper.isEmpty(mykey) << std::endl; // Should print false, as the key exists and is not empty
    wrapper[mykey]->show(); 
    std::cout << "isempty: " << wrapper.isEmpty(mykey) << std::endl; // Should print false, as the key exists and is not empty
    auto p2 = std::move(wrapper[mykey]);
    std::cout << "isempty: " << wrapper.isEmpty(mykey) << std::endl; // Should print false, as the key exists and is not empty

    // This is a placeholder for the actual test code for the map wrapper.
    // You can implement your test cases here to verify the functionality of the map wrapper.
}

void test_map_wrapper()
{
    test_map_wrapper_init(true); // Test with auto-initialization enabled    
    test_map_wrapper_init(false); // Test with auto-initialization disabled
}
