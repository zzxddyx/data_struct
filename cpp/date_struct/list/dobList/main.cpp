#include<iostream>
#include "DobList.h"
using namespace std;

int main(void)
{
    DobList<int> *head = new DobList<int>;
    for (int i = 10; i < 20; ++i)
    {
        //head->InsertHead(i);
        head->InsertTail(i);
    }

    head->Show();
    head->DeleteByHead();
    head->Show();

    head->DeleteByValue(18);
    head->Show();

    head->DeleteByTail();
    head->Show();

    int result = head->SearchByValue(17);
    cout << "result : " << result << endl;
    head->Show();

    head->FreeList();
    head->Show();

    return 0;
}
