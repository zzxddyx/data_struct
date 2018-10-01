#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> i_vec{0,1,2,3,3,4,5,6,7,8,6};
    auto cnt = count(i_vec.begin(), i_vec.end(), 4);
    cout << cnt << endl;

    auto sum = accumulate(i_vec.begin(), i_vec.end(), 0);
    cout << sum << endl;

    vector<double> d_vec{1.1,2.2,3.3,4.4,5.5};
    auto xsum = accumulate(d_vec.begin(), d_vec.end(), static_cast<double>(0));
    cout << xsum << endl;


    return 0;
}
