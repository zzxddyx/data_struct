#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

int main(void)
{
    ifstream in("../lambda/text.txt");
    istream_iterator<string> str_in(in), eof;
    vector<string> vec(str_in, eof);

    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\t"));
    cout << endl;


    return 0;
}
