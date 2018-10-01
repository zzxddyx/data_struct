#ifndef _DECORATORIPHONE_H_
#define _DECORATORIPHONE_H_

#include "DecoratorPhone.h"

class DecoratoriPhone : public DecoratorPhone
{
    public:
        DecoratoriPhone(Phone *phone)
            :DecoratorPhone(phone)
        {}

        virtual DecoratoriPhone(){};

    public:
        void ShowDecorate()
        {
            DecoratorPhone::ShowDecorate();
            this->AddDecorator();
        }

    private:
        void AddDecorator()
        {
            std::cout << "Add BaoHuMo !" << std::endl;
        }
};

#endif //_DECORATORIPHONE_H_
