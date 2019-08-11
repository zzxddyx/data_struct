/*************************************************************************
    > File Name: privateJiCheng.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月30日 星期四 21时17分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Person
{
    public:
        void eat()
        {
            cout << "Person eat" << endl;
        }
};

class Student : private Person
{
    public:
        void study()
        {
            cout << "Student study" << endl;
        }
};

int main(void)
{
    Person p;
    Student s;

    p.eat();
    s.study();


    return 0;
}
