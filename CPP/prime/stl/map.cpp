#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<int, string> s{{1, "C++"}, {2, "Python"}};

    map<int, string>::iterator iter;
    for(iter = s.begin(); iter != s.end(); ++iter)
    {
        //int key = iter->first;
        //string value = iter->second;
        cout << iter->first << " " << (*iter).second << endl;
    }


    return 0;
}

