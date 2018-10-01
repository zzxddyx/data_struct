#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

template<typename T>
struct display
{
    void operator()(const T& v)
    {
        cout << v << " ";
    }
};

template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_union_1(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while(first1 != last1 && first2 != last2)
    {
        if(*first1 < *first2)
        {
            *result = *first1;
            ++first1;
        }
        else if(*first2 < *first1)
        {
            *result = *first2;
            ++first2;
        }
        else
        {
            *result = *first1;
            ++first1;
            ++first2;
        }
        ++result;
    }

    return copy(first2, last2, copy(first1, last1, result));
}

template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_intersection_1(InputIterator1 first1, InputIterator1 last1, 
        InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while(first1 != last1 && first2 != last2)
    {
        if(*first1 < *first2)
        {
            ++first1;
        }
        else if(*first2 < *first1)
        {
            ++first2;
        }
        else
        {
            *result = *first1;
            ++first1;
            ++first2;
            ++result;
        }
    }

    return result;
}

template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_difference_1(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while(first1 != last1 && first2 != last2)
    {
        if(*first1 < *first2)
        {
            *result = *first1;
            ++first1;
            ++result;
        }
        else if(*first2 < *first1)
        {
            ++first2;
        }
        else
        {
            ++first1;
            ++first2;
        }
    }
    return copy(first1, last1, result);
}

template<class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_symmetric_difference_1(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while(first1 != last1 && first2 != last2)
    {
        if(*first1 < *first2)
        {
            *result = *first1;
            ++first1;
            ++result;
        }
        else if(*first2 < *first1)
        {
            *result = *first2;
            ++first2;
            ++result;
        }
        else
        {
            ++first1;
            ++first2;
        }
    }

    return copy(first1, last1, copy(first2, last2, result));
}
int main(void)
{
    int arr1[] = {1,2,3,4,5,6,78,9,0};
    int arr2[] = {1,2,34,5,6,7,6,5,4,3,2};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);

    multiset<int> set1(arr1, arr1+len1);
    multiset<int> set2(arr2, arr2+len2);

    for_each(set1.begin(), set1.end(), display<int>());
    cout << endl;
    for_each(set2.begin(), set2.end(), display<int>());
    cout << endl;

    multiset<int>::iterator first1 = set1.begin();
    multiset<int>::iterator end1   = set1.end();
    multiset<int>::iterator first2 = set2.begin();
    multiset<int>::iterator end2   = set2.end();

    cout << "set_union" << ":";
    set_union(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "set_union_1" << ":";
    set_union_1(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "set_intersection" << ":";
    set_intersection(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "set_intersection_1" << ":";
    set_intersection_1(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "set_difference" << ":";
    set_difference(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "set_difference_1" << ":";
    set_difference_1(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "set_symmetric_difference" << ":";
    set_symmetric_difference(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "set_symmetric_difference_1" << ":";
    set_symmetric_difference_1(first1, end1, first2, end2, ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
