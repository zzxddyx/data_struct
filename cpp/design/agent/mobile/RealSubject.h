#ifndef _READ_SUBJECT_H_
#define _READ_SUBJECT_H_

#include "Subject.h"
#include <iostream>

class CMCC : public ITelCo
{
    public:
        virtual ~CMCC(){};

        void ReCharge(int money) 
        {
            std::cout << "ReCharge : " << money << std::endl;
        };
};


#endif //_READ_SUBJECT_H_
