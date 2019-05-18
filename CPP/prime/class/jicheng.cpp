#include<iostream>
using namespace std;

class Base
{
    public:
        Base(int data)
            :m_data(data)
        {}

        virtual void Print() 
        {
            cout << this->m_data << endl;
        }

    private:
        int m_data;

};

class Drived : public Base
{
    public:
        Drived(int data = 0, int bData = 0)
            :Base(bData), m_data(data)
        {
        }

        virtual void Print()
        {
            cout << m_data << endl;
        }
    private:
        int m_data = 0;
};

int main(void)
{
    Base *p = new Drived(10, 20);
    p->Print();

    return 0;
}
