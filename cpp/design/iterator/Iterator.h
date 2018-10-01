#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include <string>
using std::string;

class Iterator
{
    public:
        virtual string First() = 0;
        virtual string Next() = 0;
        virtual string getCur() = 0;
        virtual bool isEnd() = 0; 
};

#endif //_ITERATOR_H_
