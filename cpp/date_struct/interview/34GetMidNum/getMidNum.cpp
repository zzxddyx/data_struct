/*************************************************************************
    > File Name: getMinArrNum.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年03月22日 星期五 08时41分31秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template<typename T>
class DynamicArray
{
    public:
        void Insert(T num)
        {
            // odd insert max
            if (((min.size() + max.size()) & 1) == 0)
            {
                if(max.size() > 0 && num < max[0])
                {
                    max.push_back(num);
                    push_heap(max.begin(), max.end(), less<T>());

                    num = max[0];

                    pop_heap(max.begin(), max.end(), less<T>());
                    max.pop_back();
                }

                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());
            }
            else
            {
                if(min.size() > 0 && min[0] < num)
                {
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<T>());

                    num = min[0];

                    pop_heap(min.begin(), min.end(), greater<T>());
                    min.pop_back();
                }

                max.push_back(num);
                push_heap(max.begin(), max.end(), greater<T>());
            }
        }

        T getMedian()
        {
            int size = min.size() + max.size();
            if(size == 0)
                return -10;

            T median = 0;
            if((size % 1) == 1)
            {
                median = min[0];
            }
            else
            {
                median = (min[0] + max[0])/2;
            }

            return median;
        }

        void out()
        {
            typename vector<T>::iterator iter = min.begin();
            for(; iter != min.end(); ++iter)
                cout << *iter << " ";
            cout << endl;

            iter = max.begin();
            for (; iter != max.end(); ++iter)
                cout << *iter << " ";
            cout << endl;
        }

    private:
        vector<T> min;
        vector<T> max;
};

int main()
{
    DynamicArray<int> a;
    a.Insert(1);
    a.Insert(2);
    a.Insert(3);
    a.Insert(4);
    a.Insert(5);

    a.out();
    cout << a.getMedian() << endl;

    return 0;
}
