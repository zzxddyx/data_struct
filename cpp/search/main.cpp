#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Search.h"

#define MAX 10

using namespace std;

int main(void)
{
    srand((unsigned)time(NULL));
    int arr[MAX] = {};
    int search_num = rand() % 20;

    for(int i = 0; i < MAX; ++i)
        arr[i] = rand() % 20;

    Search *_search = new Search();
    cout << "ready search num is : " << search_num << endl;
    _search->Print(arr, MAX);

    cout << "start seach ..........." << endl;
    //bool is_search = _search->Search_Seq(arr, MAX, search_num);
    _search->Sort(arr, MAX);
    _search->Print(arr, MAX);
    //bool is_search = _search->Search_Bin(arr, 0, MAX, search_num);

    /*
    if(is_search)
        cout << "seach result is : " << is_search << " and search value is : " << search_num << endl;
    else
        cout << "not find this value" << endl;
        */

    return 0;
}
