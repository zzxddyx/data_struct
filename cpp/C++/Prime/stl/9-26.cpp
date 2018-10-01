#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(void)
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    int size = sizeof(ia)/sizeof(int);
    vector<int> vi(ia, ia + size);
    list<int> li;
    for (auto i = 0; i < size; ++i)
    {
        li.push_back(ia[i]);
    }

    for (auto x : vi){ cout << x << ' '; } cout << endl;
    for (auto x : li){ cout << x << ' '; } cout << endl;

    auto iterv = vi.begin();
    while (iterv != vi.end())
    {
        if (*iterv % 2)
        {
            ++iterv;
        }
        else
        {
            iterv = vi.erase(iterv);
        }
    }
    for (auto x : vi){ cout << x << ' '; } cout << endl;

    auto iterl = li.begin();
    while (iterl != li.end())
    {
        if (*iterv % 2)
        {
            iterl = li.erase(iterl);
        }
        else
        {
            ++iterl;
        }
    }

    for (auto x : li){ cout << x << ' '; } cout << endl;

    return 0;
}
