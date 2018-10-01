#include<iostream>
#include "SigList.h"
#include "DataStruct.h"
using namespace std;

int main(void)
{
    SigList<int> *my_list = new SigList<int>;
    for (int i = 0; i < 10; ++i)
    {
        my_list->InsertTail(i);
        my_list->InsertTail(i);
    }

    /*
    int del_value = 5;
    my_list->DeleteByValue(del_value);
    my_list->Show();

    int fid_value = 6;
    DataStruct<int> *find = my_list->SearchValue(fid_value);
    if (find != NULL)
    {
        cout << "find this value : " << find->data << endl;
    }
    else
    {
        cout << "find : " << find << endl;
    }
    */

    //my_list->DeleteHead();
    //my_list->DeleteTail();
    //my_list->Show();
    //cout << "list is empty : " << my_list->isEmpty() << endl;
    
    /*
    my_list->Show();
    my_list->FanZhuan();
    my_list->Show();
    */

    /*
    cout << my_list->CheckHuan() << endl;

    my_list->Show();
    my_list->DelIndexValue(9);
    */
    my_list->Show();
    //my_list->DeleSameValue();
    my_list->DeleteSameValue1();
    my_list->Show();



    return 0;
}

