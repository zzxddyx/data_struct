#include "class.h"

Class::Class()
    :i_num(0), s_str()
{
    cout << "in function Class()" << endl;
}

Class::Class(int i, string s)
    :i_num(i), s_str(s)
{
    cout << "in function Class(param)" << endl;
}

Class::Class(Class &ref)
    :i_num(ref.i_num), s_str(ref.s_str)
{
    cout << "in function Class(&ref)" << endl;
}

Class&
Class::operator=(Class &ref)
{
    this->i_num = ref.i_num;
    this->s_str = ref.s_str;
    cout << "in function operator Class(&ref)" << endl;
}
Class::~Class()
{
    cout << "in function ~Class : " << endl;
}
