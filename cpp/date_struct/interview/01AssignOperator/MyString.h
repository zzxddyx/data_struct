#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class MyString {
    public:
        MyString(const char *str = nullptr);
        MyString(const MyString &ref);
        virtual ~MyString();

    public:
        MyString& operator=(const MyString &ref);

    public:
        void Print();

    private:
        char *m_str;
};

#endif //_MYSTRING_H_
