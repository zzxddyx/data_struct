#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool is_big_6(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}


int main(void)
{
    vector<string> str_vec;
    const int max_size = 6;
    str_vec.push_back("aaaaaa");
    str_vec.push_back("aaaaaa");
    str_vec.push_back("aaaa");
    str_vec.push_back("aaaa");
    str_vec.push_back("aaaaaa");
    str_vec.push_back("aaaaa");
    str_vec.push_back("aaaaaa");

    auto fun_big_6 = bind(is_big_6, _1, max_size);

    auto count = count_if(str_vec.begin(), str_vec.end(), fun_big_6);
    cout << count << endl;


    return 0;
}
