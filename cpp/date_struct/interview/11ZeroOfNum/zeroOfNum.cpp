#include<iostream>
using namespace std;

int Count1(int n)
{
    int count = 0;

    while(n)
    {
        ++count;
        n = n & (n-1);
    }

    return count;
}

int Count2(int n)
{
    int flag = 1;
    int count = 0;
    while(flag)
    {
        if (flag & n)
            count++;

        flag = flag << 1;
    }
    return count;
}

int main(void)
{
    int n = 9;
    cout << Count1(n) << endl;

    return 0;
}
