#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    vector<string> vs{"hello", "lua", "c++", "python", "nodejs"};
    int size = 6;

    vector<string>::iterator res = find_if(vs.begin(), vs.end(), [size](const string &s) {return s.size() >= size; });
    cout << *res << endl;
    for_each(res, vs.end(), [](const string &s){cout << s << endl;});

    return 0;
}

