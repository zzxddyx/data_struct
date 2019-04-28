#include<iostream>
using namespace std;

class Base
{
    public:
        Base(int data)
            :m_data(data)
        {}
    protected:
        void Print() 
        {
            cout << this->m_data << endl;
        }

        int m_data;

};

int main(void)
{
    Base b(10);
    b.Print();

    return 0;
}
