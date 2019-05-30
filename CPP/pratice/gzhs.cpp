#include <iostream>

class Class
{
    public:
        Class()
        {
            Class(10);
        }

        Class(int value)
            :mValue(value)
        {}

        void print()
        {
            std::cout << mValue << std::endl;
        }

    private:
        int mValue = 0;
};

int main(void)
{
    Class c;
    c.print();

    return 0;
}
