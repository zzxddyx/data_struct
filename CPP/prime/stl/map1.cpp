#include <iostream>
#include <map>
using namespace std;

typedef struct RoleInfo
{
    int sno;
    string name;
    int age;
    string tel;
}RoleInfo;

int main(void)
{
    map<int, RoleInfo*> infos;
    RoleInfo *r1 = new RoleInfo;
    r1->sno = 1;
    r1->name = "Name";
    r1->age = 34;
    r1->tel="18812341234";

    infos.insert({1, r1});

    map<int, RoleInfo*>::iterator iter;
    for(iter = infos.begin(); iter != infos.end(); ++iter)
    {
        int identity = iter->first;
        RoleInfo* info = iter->second;

        cout << identity << " " << info->name << " " << info->tel  << endl;
    }

    return 0;
}
