#include "point_class.h"

point_class::point_class()
    :ps(new string()), i(0), use(new size_t(1))
{
    cout << "in function point_class() : use is " << *this->use << endl;
}

point_class::point_class(string _s, int _i)
    :ps(new string(_s)), i(_i), use(new size_t(1))
{
    cout << "in function point_class(string, int) : " << *this->ps << " " << this->i << " use is :" << *this->use << endl;
}

point_class::point_class(const point_class &ref)
    :ps(ref.ps), i(ref.i), use(ref.use)
{
    ++*use;
    cout << "in function point_class(point_class &)" << *use << endl;
}

point_class&
point_class::operator=(point_class &ref)
{
    ++*ref.use;
    if (--*this->use == 0)
    {
        delete ps;
        delete use;
    }

    this->ps = ref.ps;
    this->i = ref.i;
    this->use = ref.use;
    cout << "in function operator point_class( &)" << *this->use << endl;
    return *this;
}

point_class::~point_class()
{
    if (--*this->use == 0)
    {
        delete ps;
        delete use;
    }

    cout << "in function ~point_class()" << *this->use << endl;
}

