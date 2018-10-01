#ifndef _DECORATORNOKIAPHONE_H_
#define _DECORATORNOKIAPHONE_H_

#include "DecoratorPhone.h"

class DecoratorNokiaPhone : public DecoratorPhone
{
    public:
        DecoratorNokiaPhone(Phone *phone)
            DecoratorPhone(Phone)
            {}

        ~DecoratorNokiaPhone(){};

    public:
        void ShowDecorate()
        {
            DecoratorPhone::ShowDecorate();
            this->AddDecorator();
        }

    private:
        void AddDecorator()
        {
            std::cout << "Add GuaJian" << std::endl;
        }
};

#endif //_DECORATORNOKIAPHONE_H_
