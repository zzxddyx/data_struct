#include "list.h"

int main(void)
{
    NODE *p1 = create(1);
    NODE *p2 = create(3);
    NODE *p3 = create(5);
    NODE *p4 = create(7);
    NODE *p5 = create(9);
    NODE *p6 = create(11);

    connect(p1, p2);
    connect(p2, p3);
    connect(p3, p4);
    connect(p4, p5);
    connect(p5, p6);
    connect(p6, NULL);

    NODE *pp1 = create(2);
    NODE *pp2 = create(4);
    NODE *pp3 = create(6);
    NODE *pp4 = create(8);
    NODE *pp5 = create(10);
    NODE *pp6 = create(12);

    connect(pp1, pp2);
    connect(pp2, pp3);
    connect(pp3, pp4);
    connect(pp4, pp5);
    connect(pp5, pp6);
    connect(pp6, NULL);


    /*  
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
    std::cout << "insert node : ";
    print(res);

    res = delets(p1, 1);
    std::cout << "delete node : ";
    print(res);

    res = reverse(p1);
    std::cout << "reverse : ";
    print(res);

    res = search_mid(p1);
    std::cout << "mid node is : " << res->data << std::endl;

    res = sort(p1);
    std::cout << "sort list : ";
    print(res);

    NODE *loop = isLoop(p1);
    std::cout << "check is loop : " << loop->data << std::endl;
    NODE *start = loopStart(p1);
    std::cout << "loop start is : " << start->data << std::endl;
    */

    NODE *res = mergeList(p1, pp1);
    std::cout << "merge is : ";
    print(res);

    return 0;
}
