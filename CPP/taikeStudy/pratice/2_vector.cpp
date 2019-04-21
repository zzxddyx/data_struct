/*************************************************************************
    > File Name: 2_vector.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年04月21日 星期日 15时54分33秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int> &vec)
{
    std::vector<int>::const_iterator iter = vec.begin();
    while(iter != vec.end())
    {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl;
}

std::vector<int> changeOrder(std::vector<int> &obj, int pos)
{
    if ((pos <= 0) || (pos >= obj.size()))
        return obj;

    std::vector<int> tmp(obj.begin()+pos+1, obj.end());
    tmp.push_back(obj[pos]);
    tmp.insert(tmp.end(), obj.begin(), obj.begin()+pos);

    return tmp;
}

void changeOrder1(std::vector<int> &obj, int pos)
{
    if ((pos <= 0) || (pos >= obj.size()))
        return;

    int objLen = obj.size();
    for(int index = 0; index < pos; ++index)
        obj.push_back(obj[index]);

    int tmp = obj[pos];
    for (int index = 1; index < obj.size()-pos; ++index)
        obj[index-1] = obj[index+pos];

    std::vector<int>::iterator iter;
    for (iter = obj.begin()+objLen; iter != obj.end();)
        iter = obj.erase(iter);


    print(obj);
}

int main(void)
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    //print(vec);

    std::vector<int> a = changeOrder(vec, 4);
    changeOrder1(vec, 4);
    //print(a);
    return 0;
}
