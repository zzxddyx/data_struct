#ifndef WEISHENG_H_
#define WEISHENG_H_

#include <iostream>

class WeiSheng
{
    public:
        WeiSheng()
        {
            std::cout << "Wei Sheng" << std::endl;
        }
        ~WeiSheng()
        {}

    public:
        void Exec()
        {
            std::cout << "I'm Wei Sheng" << std::endl;
        }
};

#endif //WEISHENG_H_
