#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    pair<string, int> si_pair;
    vector<pair<string, int>> vec;

    string s;
    int i;

    while(cin >> s >> i)
    {
        if (s == "xxx" or i == 0)
        {
            break;
        }
        //si_pair{s, i};
        //si_pair = make_pair(s, i);
        si_pair = pair<string, int>(s, i);
        vec.push_back(si_pair);
    }

    cout << endl << endl << endl;
    for (auto &x : vec)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
