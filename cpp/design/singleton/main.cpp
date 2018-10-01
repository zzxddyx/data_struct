#include "Singleton.h"

int main()
{
    Singleton *m = Singleton::getInstance();

    m->show();

    return 0;
}
