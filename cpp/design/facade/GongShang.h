#ifndef _GONGSHANG_H_
#define _GONGSHANG_H_

#include <iostream>

class GongShang
{
    public:
        GongShang()
        {
            std::cout << "Gong Shang" << std::endl;
        }
        ~GongShang()
        {}

    public:
        void Exec()
        {
            std::cout << "I'm Gong Shang" << std::endl;
        }
};

#endif //_GONGSHANG_H_
