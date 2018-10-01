#include "Value_class.h"

Value_class::Value_class()
    :ps(new string()), i(0)
{
    cout << "in function Value_class()" << endl;
}

/*  
Value_class::Value_class(const string &s = string())
    :ps(new string(s)), i(0)
{
    cout << "in function Value_class(const string)" << endl;
}
*/

Value_class::Value_class(const string &s, int)
    :ps(new string(s)), i(i)
{
    cout << "in function Value_class(string, int)" << endl;
}

Value_class::Value_class(const Value_class &ref)
    :ps(new string(*ref.ps)), i(ref.i)
{
    cout << "in function Value_class(Value_class &)" << endl;
}

Value_class&
Value_class::operator=(Value_class &ref)
{
    string* new_ps = new string(*ref.ps);
    delete ps;

    this->ps = new_ps;
    this->i = ref.i;
    cout << "in function operator Value_class(Value_class &)" << endl;
    return *this;
}

Value_class::~Value_class()
{
    delete ps;
    cout << "in function ~Value_class()" << endl;
}
