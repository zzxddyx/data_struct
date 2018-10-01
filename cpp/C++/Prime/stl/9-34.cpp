#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    vector<int> vi{0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();

    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            cout << "In if" << endl;
        }
        cout << "In while" << endl;
        ++iter;
    }

    for (auto x : vi)
    {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
