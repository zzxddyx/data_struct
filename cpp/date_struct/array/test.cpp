#include<iostream>
using namespace std;

int main(void)
{
    for (int j = 0; j < 10; ++j)
    {
        for (int i = 9; i < 20; ++i)
        {
            if (i == j)
            {
                break;
            }
            cout << i << endl;
        }

    }

    return 0;
}

