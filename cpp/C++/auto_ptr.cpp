#include<iostream>
using namespace std;

void func()
{
    auto_ptr<string> ps(new string("jjhou"));

    cout << *ps << endl;
    cout << ps->size() << endl;
}

int main(void)
{
    func();
    return 0;
}
    
