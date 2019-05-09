#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void split(const string &s, vector<string> &vec, const char flag)
{
    vec.clear();
    istringstream is(s);
    string tmp;

    while(getline(is, tmp, flag))
    {
        vec.push_back(tmp);
    }
}

int main(void)
{
    string s = "The study, published Monday in the medical journal JAMA, also found that the blood concentration of three of the ingredients continued to rise as daily use continued and then remained in the body for at least 24 hours after sunscreen use ended.";

    vector<string> res;

    split(s, res, ' ');

    vector<string>::iterator iter;
    for (iter = res.begin(); iter != res.end(); ++iter)
    {
        cout << *iter << endl;
    }



    return 0;
}

