#include <iostream>
#include <memory>

class Base
{
    public:
        Base(int data = 20)
            :mData(data)
        {}

        virtual void Print()
        {
            std::cout << mData << std::endl;
        }
    private:
        int mData = 10;
};

class Derived : public Base
{
    public:
        Derived(int value = 50)
            :mValue(value)
        {
        }

        virtual void Print()
        {
            std::cout << mValue << std::endl;
        }

    private:
        int mValue = 30;
};

int main(void)
{
    std::shared_ptr<Base*> ptr = std::make_shared(new Derived);
    ptr->Print();

    return 0;
}
