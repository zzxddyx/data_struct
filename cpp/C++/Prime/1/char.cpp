#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    /* 
    cout << "Hello World" << endl;

    //cout << 'Hello World' << endl;

    char str[] = "Hello World";
    cout << &str << endl;
    printf("%x\n", &str);
    
    int *p;
    p = (int*)0x7fff29bf81d0;
    cout << *p << endl;

    char *P;
    p = 0x7fff8d586010;
    cout << p << endl;

    cout << "Hello" << '\n' ;
    cout << "----------------" << endl;

    cout << L'a' << endl;
    printf("%d, %c, %x\n", 'a');
    cout << 42ULL << endl;


    cout << "2M" << '\n';
    cout << 2 << '\t' << 'M' << '\n';
    */

    vector<string> vec{"Hello", "World", "C++", "Fuck"};
    vector<string>::iterator iter = vec.begin();

    cout << *iter++ << endl;
    cout << iter++->empty() << endl;
    cout << iter->empty() << endl;


    return 0;
}
