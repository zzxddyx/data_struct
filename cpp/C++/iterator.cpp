/*************************************************************************
    > File Name: iterator.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2017年09月27日 星期三 14时46分56秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    const int arraySize = 7;
    int ia[arraySize] = {1,2,3,4,5,6,7};

    vector<int> ivect(ia, ia+arraySize);
    list<int> ilist(ia, ia+arraySize);
    deque<int> ideque(ia, ia+arraySize);

    vector<int>::iterator it1 = find(ivect.begin(), ivect.end(), 4);
    if (it1 == ivect.end())
        cout << "4 is not find" << endl;
    else
        cout << "4 find" << *it1 << endl;

    list<int>::iterator it2 = find(ilist.begin(), ilist.end(), 5);
    if (it2 == ilist.end())
        cout << "5 is not find" << endl;
    else
        cout << "5 find" << *it2 << endl;

    deque<int>::iterator it3 = find(ideque.begin(), ideque.end(), 7);
    if (it3 == ideque.end())
        cout << "7 is not find" << endl;
    else
        cout << "7 is find" << *it3 << endl;

    return 0;
}

