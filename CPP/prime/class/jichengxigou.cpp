#include <iostream>
#include <cstring>

class Base
{
    public:
        Base(const char* ptr = nullptr)
        {
            if (ptr == nullptr)
            {
                mPtr = new char[1];
                strcpy(mPtr, '\0');
            }
            else
            {
                mPtr = new char[strlen(ptr)+1];
                strcpy(mPtr, ptr);
            }
        }

    private:
        char *mPtr = nullptr;

};
