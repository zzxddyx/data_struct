#ifndef _BAG_IMAGE_H_
#define _BAG_IMAGE_H_

#include "Image.h"
#include <string>
#include <iostream>
using std::string;

class BigImage : public Image
{
    public:
        BigImage(string name, double size)
            :m_name(name), m_size(size)
        {
        }

        void Show()
        {
            std::cout << "The Picture is : " << this->m_name << " size : " << this->m_size << std::endl;
        }

        double getSize()
        {
            return this->m_size;
        }

        string getName()
        {
            return this->m_name;
        }
    private:
        string m_name;
        double m_size;
};

#endif //_BAG_IMAGE_H_
