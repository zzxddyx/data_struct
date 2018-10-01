#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    map<string, int> simap;
    simap["a"] = 1;
    simap["b"] = 2;
    simap["c"] = 3;
    simap["d"] = 4;

    pair<string, int> value("e", 5);
    simap.insert(value);

    pair<string, int> v("a", 45);
    simap.insert(v);

    map<string, int>::iterator iter = simap.begin();
    for( ; iter != simap.end(); ++iter)
    {
        cout << iter->first << " ";
        cout << iter->second << " " << endl;
    }
    cout << endl;

    cout << simap["e"] << endl;

    map<string, int>::iterator iter1;
    iter1 = simap.find("a");
    if(iter1 != simap.end())
    {
        cout << "is find :" << iter1->second << endl;
    }

    iter1->second = 100;
    cout << iter1->second << endl;

    return 0;
}

