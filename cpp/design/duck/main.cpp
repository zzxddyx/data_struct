#include "Duck.h"
#include "FlyWithWings.h"
#include "Quack.h"

class MallDuck : public Duck
{
    public:
        /*  
        MallDuck(FlyBehavior *fly_behavior = new FlyWithWings(), QuackBehavior *quack_behavior = new Quack())
            :Duck(fly_behavior, quack_behavior)
        {}
        */
};

int main(void)
{
    Duck *mall_duck = new MallDuck();
    mall_duck->setFlyBehavior(new FlyWithWings());
    mall_duck->performFly();
    //mall_duck->performQuack();

    return 0;
}
