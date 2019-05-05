#include<iostream>
using namespace std;

class BaseA
{
    public:
        BaseA(int a = 20)
            :m_a(a)
        {}

        void print()
        {
            cout << m_a << endl;
        }
    private:
        int m_a = 10;
};

int main()
{
    //BaseA a();  
    BaseA a(30);

    a.print();

    return 0;
}

