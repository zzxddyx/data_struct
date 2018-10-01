#include "iPhone.h"
#include "Phone.h"

int main()
{
    Phone *phone1 = new iPhone("5436");

    Phone *decor1 = new DecoratorPhone(phone1);
    decor1->ShowDecorate();

    delete phone1;
    delete decor1;

    return 0;
}
