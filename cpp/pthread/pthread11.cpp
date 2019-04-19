#include <iostream>
#include <thread>

using namespace std;

void output(int i)
{
    cout << i << endl;
}

int main(void)
{
    for (int i = 0; i < 4; ++i)
    {
        thread t(output, i);
        t.detach();
    }

    return 0;
}
