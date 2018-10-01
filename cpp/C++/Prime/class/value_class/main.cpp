#include "Value_class.h"

int main(void)
{
    Value_class a1;
    Value_class a2("hello", 20);
    Value_class a5(string("hello"));
    Value_class a3(a2);
    Value_class a4;
    a4 = a1;

    return 0;
}
