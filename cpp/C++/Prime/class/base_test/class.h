#include <iostream>
#include <string>
using namespace std;

class Class
{
    public:
        Class();
        Class(int i, string s);
        Class(Class &ref);
        Class& operator=(Class &ref);
        ~Class();
    private:
        int i_num;
        string s_str;
};



