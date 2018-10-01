#include "QuackBehavior.h"

class MuteQuack : public QuackBehavior
{
    public:
        virtual void quack()
        {
            std::cout << "Mute Quack !" << std::endl;
        }
};
