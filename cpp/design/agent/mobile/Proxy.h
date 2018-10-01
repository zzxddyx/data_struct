#ifndef _PROXY_H_
#define _PROXY_H_

#include "Subject.h"
#include "RealSubject.h"

class Proxy : public ITelCo
{
    public:
        Proxy()
        {
            p_mCmcc = new CMCC();
        }

        virtual ~Proxy()
        {
            if (NULL != p_mCmcc)
            {
                delete p_mCmcc;
                p_mCmcc = NULL;
            }
        }

    public:
        void ReCharge(int money)
        {
            if (money <= 50)
            {
                std::cout << "Not Enough : must > 50" << std::endl;
            }
            else
            {
                p_mCmcc->ReCharge(money);
            }
        }
    private:
        CMCC *p_mCmcc;
};


#endif //_PROXY_H_
