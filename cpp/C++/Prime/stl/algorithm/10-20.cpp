#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

void Print(const vector<string> &v)
{
    for (const auto &s : v)
    {
        cout << s << ' ';
    }
    cout << endl;
}

void sort_string(vector<string> &str)
{
    Print(str);
    sort(str.begin(), str.end());
    Print(str);

    auto end_enique = unique(str.begin(), str.end());
    Print(str);

    str.erase(end_enique, str.end());
    Print(str);
}

void bigger_count(vector<string> &str, vector<string>::size_type size)
{
    sort_string(str);
    stable_sort(str.begin(), str.end(), [](string &s1, string &s2){ return s1.size() < s2.size();});

    auto count = count_if(str.begin(), str.end(), [=](string &s) { return s.size() >= size; });

    cout << count << endl;

}


int main(void)
{
    vector<string> str_vec{"judje", "algorithm", "vector", "xshell"};

    /*  
    str_vec.push_back("Hello C++");
    str_vec.push_back("Hello");
    str_vec.push_back(" C++");
    str_vec.push_back("Hello C++ and ");
    str_vec.push_back("Hello C++ and Lua");
    str_vec.push_back("Hello C++ and Json");
    */

    auto big_size = 6;
    bigger_count(str_vec, big_size);


    return 0;
}
