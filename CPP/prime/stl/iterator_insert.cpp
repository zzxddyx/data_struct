#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int> &vec)
{
    vector<int>::const_iterator iter;
    for (iter = vec.begin(); iter != vec.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main(void)
{
    vector<int> v;

    v.insert(v.begin(), 4, 5);

    vector<int>::iterator iter = v.begin();
    for (int i = 10; i < 15; ++i)
    {
        iter = v.insert(iter, i);

    }

    print(v);


    return 0;
}


