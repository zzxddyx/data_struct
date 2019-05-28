#include <iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout << "Base() default construct" << endl;
        }
        Base(int value)
            :mValue(value)
        {
            cout << "Base(int) param construct" << endl;
        }
        ~Base()
        {
            cout << "Base destruct" << endl;
        }
    private:
        int mValue;
};

Base construct(Base t)
{
    return t;
}

int main(void)
{
    Base b1 = construct(5);
    //Base b2 = construct(b1);
    Base b3 = construct(4);

    return 0;
}
