#include "doubleList.h"

int main(void)
{
    NODE *p1 = create(1);
    NODE *p2 = create(2);
    NODE *p3 = create(3);
    NODE *p4 = create(4);
    NODE *p5 = create(5);

    connect(p1, p2);
    connect(p2, p3);
    connect(p3, p4);
    connect(p4, p5);
    connect(p5, NULL);

    std::cout << "double list length : " << length(p1) << std::endl;
    std::cout << "double list node is : ";
    print(p1);

    return 0;
}
