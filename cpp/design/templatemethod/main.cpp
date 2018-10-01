#include "Cook.h"
#include "Eat.h"
#include "Kfc.h"

int main(void)
{
    Eat *eat = new Kfc();
    eat->feed();

    Eat *cook = new Cook();
    cook->feed();
    return 0;
}


