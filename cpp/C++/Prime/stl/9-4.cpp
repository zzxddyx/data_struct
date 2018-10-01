#include <iostream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

bool find_num(vector<int> &vi, int num)
{
    auto begin = vi.begin();
    auto end = vi.end();
    while ( begin != end )
    {
        if (*begin == num)
        {
            return true;
        }
        ++begin;
    }

    return false;
}

int find_value(vector<int> &vi, int num)
{
    auto begin = vi.begin();
    auto end = vi.end();
    while ( begin != end )
    {
        if (*begin == num)
        {
            return *begin;
        }
        ++begin;
    }

    return 101;
}

int main(void)
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    auto back = find_num(vi, 70);
    auto xxx = find_value(vi, 4);
    cout << back << ' ' << xxx << endl;


    return 0;
}
