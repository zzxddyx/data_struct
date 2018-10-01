#include "point_class.h"

int main(void)
{
    point_class a1;
    point_class a2(a1);

    point_class s2("sunny", 88);
    point_class s3 = s2;
    point_class s4 = s2;

    point_class d1("good luck", 99);
    point_class d2;
    d2 = d1;



    return 0;
}
