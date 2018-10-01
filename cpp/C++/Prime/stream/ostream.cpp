#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    ifstream of;
    of.open("./tmp.txt");

    if (of)
    {
        string s;
        while(getline(of, s))
        {
            cout << s << endl; 
        }
    }
    else
    {
        cerr << "Open Failed" << endl;
    }


    return 0;
}
