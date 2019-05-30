/*************************************************************************
    > File Name: jichengcopy.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月27日 星期一 22时30分10秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Base
{
    public:
        Base(int num = 0)
            :mBase(num)
        {
            cout << "Base(int)" << endl;
        }
        Base(Base &ref)
            :mBase(ref.mBase)
        {
            cout << "Base(ref&)" << endl;
        }
        virtual void print()
        {
            cout << mBase << endl;
        }
    private:
        int mBase = 0;
};

class Derived : public Base
{
    public:
        Derived(int b, int d)
            :Base(b), mDerived(d)
        {
            cout << "Derived(int ,int)" << endl;
        }
        Derived(Derived &ref)
            :Base(ref), mDerived(ref.mDerived)
        {
            cout << "Derived(Derived&ref)" << endl;
        }
        virtual void print()
        {
            cout << mDerived << endl;
        }
    private:
        int mDerived = 0;
};

int main(void)
{
    Base b1(1);
    Derived d1(2, 3);
    b1.print();
    d1.print();

    Derived d2(d1);
    d2.print();

    return 0;
}
