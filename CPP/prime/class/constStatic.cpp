#include <iostream

class Base
{
    public:
        const static int mA = 10;
        static const int mB = 10;
};

int main(void)
{
    Base *p = new Base;

    return 0;
}
