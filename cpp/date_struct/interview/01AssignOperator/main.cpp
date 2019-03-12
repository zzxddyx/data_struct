#include "MyString.h"

int main(void) 
{
    MyString str1("hello");
    //str1.Print();
    //
    MyString str2("world");
    //str2.Print();

    MyString str3("test");
    str3 = str2 = str1;
    str1.Print();
    str2.Print();
    str3.Print();

    
    return 0;
}
