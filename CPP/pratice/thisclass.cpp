/*************************************************************************
    > File Name: thisclass.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月23日 星期四 21时59分48秒
 ************************************************************************/

#include <iostream>
using namespace std;

class MyClass
{
    public:
        int data;

        MyClass(int data)
        {
            this->data = data;
        }

        void print()
        {
            cout << data << endl;
            cout << "hello" << endl;
        }
};

int main(void)
{
    MyClass* pObj;
    pObj = new MyClass(1);
    pObj->print();
    pObj[0].print();
    pObj[1].print();
    pObj[1000].print();

    return 0;
}
