#include "Beverage.h"
#include "Blend.h"
#include "DarkRoast.h"
#include "Decorator.h"
#include "Milk.h"
#include "Mocha.h"
#include "Soy.h"

int main()
{

    shared_ptr<Beverage> blendObserved(new Blend()) ; 
    shared_ptr<Beverage> darkObserved(new DarkRoast());

    shared_ptr<Decorator> blendWithMilk(new Milk()); 
    blendWithMilk->setObserver(blendObserved);

    shared_ptr<Decorator> blendWithMocha(new Mocha()); 
    blendWithMocha->setObserver(blendObserved);

    shared_ptr<Decorator> blendWithSoy(new Soy()); 
    blendWithSoy->setObserver(blendObserved);

    cout<<blendWithMilk->cost()<<endl; 
    cout<<blendWithMocha->cost()<<endl; 
    cout<<blendWithSoy->cost()<<endl; 
    return 0; 
}

