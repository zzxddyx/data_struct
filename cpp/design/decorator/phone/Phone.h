#ifndef _PHONE_H_
#define _PHONE_H_

#include <iostream>

class Phone
{
    public:
        Phone(){};
        virtual ~Phone(){};
        virtual void ShowDecorate() = 0;
};

#endif //_PHONE_H_
