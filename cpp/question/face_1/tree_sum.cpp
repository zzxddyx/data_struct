#include<iostream>
using namespace std;

void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
    if(pRoot==NULL)
        return;
    std::vector<int> path;
    int currentSum=0;
    FindPath(pRoot,expectedSum,path,currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum)
{
    currentSum +=pRoot->value;
    path.push_back(pRoot->value);
    //如果是叶结点,并且路径上结点的和等于输入的值，打印出这条路径
    bool isLeaf =(pRoot->lchild==NULL&&pRoot->rchild==NULL);
    if(currentSum==expectedSum&&isLeaf)
    {
        printf("A path is found:");
        std::vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();++iter)
            printf("%d\t",*iter);
        printf("\n");
    }
    //如果不是叶结点,则遍历它的子结点
    if(pRoot->lchild!=NULL)
        FindPath(pRoot->lchild,exception,path,currentSum);
    if(pRoot->rchild!=NULL)
        FindPath(pRoot->rchild,expection,path,currentSum);

    //在返回父结点之前,在路径上删除当前结点
    path.pop_back();
}
