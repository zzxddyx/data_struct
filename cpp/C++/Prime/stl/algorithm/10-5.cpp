#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<const char*> c1{"Hello C++"};
    vector<const char*> c2{"Hello C+++"};

    auto result = equal(c1.begin(), c1.end(), c2.begin());
    cout << result << endl;

    vector<int> test{1,2,3,4,5,6,7,8,9,0};
    fill_n(test.begin(), 5, 0);
    copy(test.begin(), test.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    for (auto x : test)
    {
        cout << x << endl;
    }


    return 0;
}
