#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

int main(void)
{
    string text = "It will be the first direct flight to link the two cities, according to Guangzhou Baiyun International Airport. The flight will be operated by South African Airways and will shorten the travel time to 13 hours and 40 minutes. Flying three times a week, the outbound flight will leave Guangzhou at 10:15 p.m. every Monday, Thursday and Saturday and arrive in Johannesburg at 5:30 a.m. local time the next day. The return flight will take off from Johannesburg at 7:25 p.m. local time every Wednesday, Friday and Sunday, and land in Guangzhou at 3:05 p.m. the next day. China has been South Africa's largest trading partner for nine consecutive years. The air route is expected to boost tourism and business communication between the two cities.";

    char* c_text = const_cast<char *>(text.c_str());
    char sep[] = " ";
    char *p = nullptr;

    p = strtok(c_text, sep);
    vector<string> res;
    while (p)
    {
        res.push_back(p);
        p = strtok(NULL, sep);
    }

    map<string, int> record;
    vector<string>::iterator iter;
    for (iter = res.begin(); iter != res.end(); ++iter)
    {
        int count = record[*iter] ? record[*iter] : 0;
        record[*iter] = count+1;
    }

    map<string, int>::iterator miter;
    for (miter = record.begin(); miter != record.end(); ++miter)
    {
        cout << miter->first << " " << miter->second << endl;
    }
    
    return 0;
}

