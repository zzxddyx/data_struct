#include "Singleton.h"

int main()
{
    Singleton *p = Singleton::getInstance();
    p->show();

    return 0;
}
