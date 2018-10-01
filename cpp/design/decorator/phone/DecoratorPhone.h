#ifndef _DECORATORPHONE_H_
#define _DECORATORPHONE_H_

#include "Phone"

class DecoratorPhone : public Phone
{
    public:
        DecoratorPhone(Phone *phone)
            :m_phone(Phone)
        {}
        virtual ~DecoratorPhone(){};

    public:
        virtual void ShowDecorate()
        {
            this->m_phone->ShowDecorate();
        }

    private:
        Phone *m_phone;
};

#endif //_DECORATORPHONE_H_
