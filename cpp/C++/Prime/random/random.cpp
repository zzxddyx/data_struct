#include <iostream>
#include <random>
using namespace std;

int main(void)
{
    default_random_engine e;
    uniform_real_distribution<double> u(1,2);

    for (size_t i = 0; i < 10; ++i)
    {
        cout << u(e) << endl;
    }

    return 0;
}
