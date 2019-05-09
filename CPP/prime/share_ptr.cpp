#include <iostream>
#include <memory>
using namespace std;

void print(shared_ptr<int> &ptr)
{
    cout << *ptr << endl;
    *ptr = 20;
}

int main(void)
{
    shared_ptr<int> ptr = make_shared<int>(10);
    print(ptr);
    cout << "==============" << endl;
    cout << *ptr << endl;

    return 0;
}
