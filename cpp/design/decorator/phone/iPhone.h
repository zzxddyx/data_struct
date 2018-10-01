#ifndef _IPHONE_H_
#define _IPHONE_H_

#include "Phone.h"

class iPhone : public Phone
{
    public:
        iPhone(std::string name)
            :m_name(name)
        {}

        virtual ~iPhone(){};

    public:
        void ShowDecorate()
        {
            std::cout << this->m_name << " : Decorate !" << std::endl;
        }


    private:
        std::string m_name;
};

#endif //_IPHONE_H_
