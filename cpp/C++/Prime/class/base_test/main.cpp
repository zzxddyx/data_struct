#include "class.h"

int main(void)
{
    Class a;
    Class b(10, "Hello");
    Class c(b);
    Class d = b;
    Class e;
    e = d;

    return 0;
}
