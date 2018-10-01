#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int score = 0;
    cin >> score;
    vector<string> step{"F", "D", "C", "B", "A", "A++" };
    string s;

    if ( score < 60 )
    {
        s = step[0];
    }
    else
    {
        s = step[ (score - 50 ) / 10];
    }

    cout << s << endl;

    return 0;
}
