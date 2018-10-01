#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    string xx("..class/Sales_data.cpp");
    ifstream o_fp(xx);
    vector<string> vs;
    if (o_fp)
    {
        string s;
        while( getline(o_fp, s))
        {
            vs.push_back(s);
        }
    }
    else
    {
        cerr << "failed" << endl;
    }

    o_fp.close();

    for (auto s : vs)
    {
        cout << s << endl;
    }

    return 0;
}
