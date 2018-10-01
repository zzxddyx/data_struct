#include "QuackBehavior.h"

class Squeak : public QuackBehavior
{
    public:
        virtual void quack()
        {
            std::cout << "Squeak" << std::endl;
        }
};
