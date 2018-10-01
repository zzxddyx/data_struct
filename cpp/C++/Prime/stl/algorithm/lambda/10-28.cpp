#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

int main1(void)
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    vector<int> vec_n;
    vector<int> vec_f;
    vector<int> vec_b;

    for_each(vec.begin(), vec.end(), [](const int &i){ cout << i << ' '; });
    cout << endl;
    //copy(vec.begin(), vec.end(), front_inserter(vec_f)); //vector没有front

    copy(vec.begin(), vec.end(), back_inserter(vec_b)); 
    for_each(vec_b.begin(), vec_b.end(), [](const int &i){ cout << i << ' '; });
    cout << endl;

    copy(vec.begin(), vec.end(), inserter(vec_n, vec_n.end()));
    for_each(vec_n.begin(), vec_n.end(), [](const int &i){ cout << i << ' '; });
    cout << endl;



    return 0;
}

int main(void)
{
    list<int> vec{1,2,3,4,5,6,7,8,9};
    list<int> vec_n;
    list<int> vec_f;
    list<int> vec_b;

    for_each(vec.begin(), vec.end(), [](const int &i){ cout << i << ' '; });
    cout << endl;
    copy(vec.begin(), vec.end(), front_inserter(vec_f)); //vector没有front
    for_each(vec_f.begin(), vec_f.end(), [](const int &i){ cout << i << ' '; });
    cout << endl;

    copy(vec.begin(), vec.end(), back_inserter(vec_b)); 
    for_each(vec_b.begin(), vec_b.end(), [](const int &i){ cout << i << ' '; });
    cout << endl;

    copy(vec.begin(), vec.end(), inserter(vec_n, vec_n.begin()));
    for_each(vec_n.begin(), vec_n.end(), [](const int &i){ cout << i << ' '; });
    cout << endl;



    return 0;
}
