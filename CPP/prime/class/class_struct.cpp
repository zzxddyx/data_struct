#include<iostream>
using namespace std;

struct BaseA
{
    public:
        BaseA()
            :a(4)
        {
        }
        void print()
        {
            cout << "I'm struct Base " << a << endl;
        }
    private:
        int a;
};

class BaseB
{
    public:
        BaseB()
            :a(5)
        {}
        void print()
        {
            cout << "I'm class Base " << a <<  endl;
        }
    private:
        int a;
};

int main(void)
{
    BaseA a;
    a.print();

    BaseB b;
    b.print();

    return 0;
}

