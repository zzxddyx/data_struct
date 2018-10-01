#include <iostream>
#include <functional>
#include <map>
using namespace std;

int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) { return i % j; };
struct divide
{
    int operator()(int i, int j){ return i / j; }
};

int main(void)
{
    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", minus<int>()},
        {"*", [](int i, int j) { return i*j ;}},
        {"/", divide()},
        {"%", mod},
    };

    cout << binops["+"](10, 40) << endl;
    cout << binops["-"](10, 40) << endl;
    cout << binops["*"](10, 40) << endl;
    cout << binops["/"](10, 40) << endl;
    cout << binops["%"](10, 40) << endl;


    return 0;
}
