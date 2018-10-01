#include "Singleton.h"

int main()
{
    Singleton *p = Singleton::getInstance();
    p->show();

    Singleton *pp = Singleton::getInstance();
    pp->show();

    if ( p == pp )
    {
        std::cout << "one" << std::endl;
    }

    return 0;
}
