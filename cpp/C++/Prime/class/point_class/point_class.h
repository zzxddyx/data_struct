#ifndef _POINT_CLASS_H_
#define _POINT_CLASS_H_

#include <iostream>
#include <string>
using namespace std;

class point_class
{
    public:
        point_class();
        point_class(string _s, int _i);
        point_class(const point_class &ref);
        point_class& operator=(point_class &ref);
        ~point_class();
    private:
        string *ps;
        int i;
        size_t *use;
};

#endif //_POINT_CLASS_H_
