#include <iostream>

std::string global_str;
int ff;

int main(void)
{
    std::cout << global_str << std::endl;
    std::cout << ff << std::endl;

    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i - i2 << std::endl;
    std::cout << i2 - i << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    std::cout << i - u2 << std::endl;
    std::cout << u2 - i << std::endl;

    std::cout << "------------------------------" << std::endl;
    int ii = {3.24};
    std::cout << ii << std::endl;

    int cc;
    std::string ss;
    std::cout << cc << std::endl;
    std::cout << ss << std::endl;



    return 0;
}
