#include <map>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
using namespace std;

int main(void)
{
    map<string, int> count_word;
    string word;
    ifstream is("./text.txt");

    while (is >> word)
    {
        ++count_word[word];
    }

    for (auto &x : count_word)
    {
        cout << x.first << "\t:" << x.second << endl;
    }

    return 0;
}



