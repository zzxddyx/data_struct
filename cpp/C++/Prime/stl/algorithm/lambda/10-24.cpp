#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const int i, const string &str)
{
    return i >= str.size();
}

int main(void)
{
    string str = "ezfun";
    vector<int> vi{1,2,3,4,5,6,7,87,34,23,56,76};

    auto fun_check = bind(check_size, _1, str);

    auto find = find_if(vi.begin(), vi.end(), fun_check);
    cout << *find << endl;

    return 0;
}

