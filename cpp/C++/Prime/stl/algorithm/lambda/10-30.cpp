#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
    istream_iterator<int> i_iter(cin), eof;
    vector<int> vec(i_iter, eof);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "  "));

    return 0;
}
