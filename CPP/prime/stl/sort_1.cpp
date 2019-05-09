#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

bool compare(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(void)
{
    vector<string> vs{"hello", "C++", "lua", "python"};
    copy(begin(vs), end(vs), ostream_iterator<string>(cout, " "));
    cout << endl;

    //sort(begin(vs), end(vs), compare);
    sort(vs.begin(), vs.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    copy(begin(vs), end(vs), ostream_iterator<string>(cout, " "));
    //for_each(begin(vs), end(vs), ostream_iterator<string>(cout, " "));
    cout << endl;

    return 0;
}

