#ifndef _NOKIAPHONE_H_
#define _NOKIAPHONE_H_

#include "Phone"

class NokiaPhone : public Phone
{
    public:
        NokiaPhone(std::string name)
            :m_name(name)
        {}

        virtual ~NokiaPhone(){};

    public:
        void ShowDecorate()
        {
            std::cout << this->m_name << " : Decorate !" <<  std::endl;
        }

    private:
        std::string m_name;
};

#endif //_NOKIAPHONE_H_
