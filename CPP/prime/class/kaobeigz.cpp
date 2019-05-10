#include <iostream>
#include <cstring>

class MyString
{
    public:
        MyString(const char *ptr = nullptr)
        {
            if (ptr == nullptr)
            {
                mStr = new char[1];
                strcpy(mStr, '\0');
            }
            else
            {
                mStr = new char[strlen(ptr)+1];
                strcpy(mStr, ptr);
            }
        }
        
        MyString(const MyString&) = delete;
        MyString& operator=(const MyString&) = delete;
    private:
        char *mStr = nullptr;
};
