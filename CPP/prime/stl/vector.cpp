#include <iostream>
#include <vector>
#include <string>

int main(void)
{
    //std::vector<int> v(10);
    //std::cout << v.size() << std::endl;
    //std::cout << v.capacity() << std::endl;

    std::vector<std::string> sv(10, "hi");
    //std::vector<std::string> sv{10, "hi"};// error
    for (auto &s : sv)
        std::cout << s << std::endl;

    std::cout << sv.size() << std::endl;

    return 0;
}

