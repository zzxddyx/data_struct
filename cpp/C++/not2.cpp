#include <iostream>     // std::cout
#include <functional>   // std::not2, std::equal_to
#include <algorithm>    // std::mismatch
#include <utility>
using namespace std;

int main () 
{
    int foo[] = {10,20,30,40,50};
    int bar[] = {0,15,30,45,60};

    pair<int*,int*> firstmatch, firstmismatch;

    firstmismatch = mismatch (foo, foo+5, bar, equal_to<int>());
    firstmatch = mismatch (foo, foo+5, bar, not2(equal_to<int>()));

    cout << "First mismatch in bar is " << *firstmismatch.first << '\n';//10
    cout << "First mismatch in bar is " << *firstmismatch.second << '\n';//0
    cout << "First match in bar is " << *firstmatch.first << '\n';//30
    cout << "First match in bar is " << *firstmatch.second << '\n';//30
    return 0;
}
