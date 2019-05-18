#include <iostream>

class Base
{
    public:
        virtual void print(int num = 10)
        {
            std::cout << "I'm Base: " << num << std::endl;
        }
};

class Derived : public Base
{
    public:
        virtual void print(int num = 20)
        {
            std::cout << "I'm Derived: " << num << std::endl;
        }
};

int main(void)
{
    Base* obj = new Derived;
    obj->print();

    return 0;
}
