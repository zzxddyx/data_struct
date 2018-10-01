#ifndef _VALUE_CLASS_H_
#define _VALUE_CLASS_H_

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Value_class
{
    public:
        Value_class();
        //Value_class(const string &s = string());
        Value_class(const string &s, int i = 0);
        Value_class(const Value_class &ref);
        Value_class& operator=(Value_class &ref);
        ~Value_class();
    private:
        string *ps;
        int i;
};

#endif //_VALUE_CLASS_H_
