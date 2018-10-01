#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<string> str_vec;
    str_vec.push_back("Hello C++");
    str_vec.push_back("Hello ezfun");
    str_vec.push_back("Hello");
    str_vec.push_back("Hello Lua");
    str_vec.push_back("He");

    int sz = 6;
    auto xxx = count_if(str_vec.begin(), str_vec.end(), [sz](const string &s) {return s.size() >= sz;});
    cout << xxx << endl;

    return 0;
}
