#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 消除重复元素
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, string ending)
{
    return (ctr == 1) ? word : word + ending;
}

void bigger(vector<string> &words, vector<string>::size_type size)
{
    elimDups(words);

    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){ return a.size() < b.size();});

    auto big_size = find_if(words.begin(), words.end(), [size](const string &a) { return a.size() >= size; });

    // 满足大于sz的数目
    auto count = words.end() - big_size;

    for_each(big_size, words.end(), [](const string &s){ cout << s << endl;; });
    cout << endl;
}

int main(void)
{
    vector<string> str_vec;
    str_vec.push_back("Hello C++");
    str_vec.push_back("Hello ezfun");
    str_vec.push_back("Hello");
    str_vec.push_back("Hello Lua");

    bigger(str_vec, 6);


    return 0;
}
