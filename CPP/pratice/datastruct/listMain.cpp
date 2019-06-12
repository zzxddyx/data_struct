#include "list.h"

int main(void)
{
    NODE *p1 = create(1);
    NODE *p2 = create(2);
    NODE *p3 = create(3);
    NODE *p4 = create(4);
    NODE *p5 = create(5);
    NODE *p6 = create(6);

    connect(p1, p2);
    connect(p2, p3);
    connect(p3, p4);
    connect(p4, p5);
    connect(p5, p6);
    connect(p6, NULL);

    NODE *res = NULL;
    std::cout << "length : " << length(p1) << std::endl;
    std::cout << "list node : ";
    print(p1);

    res = search(p1, 3);
    if (res != NULL)
        std::cout << "search node : " << res->data << std::endl;
    else
        std::cout << "not search the node" << std::endl;

    res = insert(p1, 7);
    print(res);


    return 0;
}
