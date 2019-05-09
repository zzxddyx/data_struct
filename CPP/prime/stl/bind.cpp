#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

bool checkSize(const string &s, const int size)
{
    return s.size() > size;
}

int main(void)
{
    vector<string> vs{"Hello", "C++", "Lua", "Nodejs", "Shell"};
    const int size = 5;

    vector<string>::iterator iter = find_if(vs.begin(), vs.end(), bind(checkSize, std::placeholders::_1, size));
    //cout << *iter << endl;
    //for_each(iter, vs.end(), [](const string &s) {cout << s << " ";});
    copy(iter, vs.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    return 0;
}

