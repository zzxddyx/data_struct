#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class ITelCo
{
    public:
        virtual ~ITelCo(){};
        virtual void ReCharge(int money) = 0;
};

#endif //_SUBJECT_H_
