#ifndef FACADE_H_
#define FACADE_H_

#include "GongShang.h"
#include "WeiSheng.h"

class Facade
{
    public:
        Facade()
        {
            m_pGongshang = new GongShang();
            m_pWeisheng = new WeiSheng();
        }

        ~Facade()
        {
            if (NULL != m_pGongshang)
            {
                delete m_pGongshang;
                m_pGongshang = NULL;
            }
            if (NULL != m_pWeisheng)
            {
                delete m_pWeisheng;
                m_pWeisheng = NULL;
            }
        }

        void Notify()
        {
            m_pGongshang->Exec();
            m_pWeisheng->Exec();
        }
    private:
        GongShang *m_pGongshang;
        WeiSheng *m_pWeisheng;
};


#endif //FACADE_H_
