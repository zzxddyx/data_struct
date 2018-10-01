#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

int main(void)
{
    vector<int> iv{1,1,2,3,3,4,5,6,6,7,7,8,8,9,9,10};
    vector<int> iv_bak;

    for_each(iv.begin(), iv.end(), [](const int &i){ cout << i << " "; });
    cout << endl;
    unique_copy(iv.begin(), iv.end(), inserter(iv_bak, iv_bak.begin()));


    for_each(iv_bak.begin(), iv_bak.end(), [](const int &i){ cout << i << " "; });
    cout << endl;

    return 0;
}
