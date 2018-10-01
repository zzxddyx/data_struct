#include <iostream>

enum Test {
    Test1,
    Test2
};

int main(void)
{
    Test x = Test2;
    std::cout << x << std::endl;

    return 0;
}
