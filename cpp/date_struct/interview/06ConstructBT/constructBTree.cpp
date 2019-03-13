#include <iostream>
#include <cstring>
#include "../common/BinaryTree.h"
using namespace std;

BTree* Construct1(char *preStrStart, char *preStrEnd, 
                 char *midStrStart, char *midStrEnd)
{
    char rootValue = preStrStart[0];
    BTree *pRoot = new BTree();
    pRoot->data = rootValue;
    pRoot->lChild = pRoot->rChild = NULL;

    // only one
    if (preStrStart == preStrEnd)
    {
        if(midStrStart == midStrEnd && midStrStart == preStrStart) 
            return pRoot;
        else
            return NULL;
    }

    // get left and right
    char *midNode = midStrStart;
    while(midNode != midStrEnd && *midNode != rootValue)
        ++midNode;

    if(midNode == midStrEnd && *midNode != rootValue)
        return NULL;

    int leftLen = midNode - midStrStart;
    char *leftPreOrderEnd = preStrStart + leftLen;

    if (leftLen > 0)
        pRoot->lChild = Construct(preStrStart+1, leftPreOrderEnd, midStrStart, midNode-1);

    if(leftLen < preStrEnd-preStrStart)
        pRoot->rChild = Construct(leftPreOrderEnd+1, preStrEnd, midNode+1, midStrEnd);

    return pRoot;
}

BTree* ConstructTree1(char *preStr, char *midStr)
{
    int preLen = strlen(preStr);
    int midLen = strlen(midStr);

    if (preStr == NULL || midStr == NULL || preLen != midLen)
        return NULL;

    return Construct(preStr, preStr+preLen-1, midStr, midStr+preLen-1);
}


int main(void) 
{
    char preStr[] = "ABDECFG";
    char midStr[] = "DBEAGFC";

    BTree *pRoot = ConstructTree(preStr, midStr);
    cout << "=====================" << endl;
    Print(pRoot);


    return 0;
}
