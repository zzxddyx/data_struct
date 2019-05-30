#include "MyString.h"

MyString::MyString()
{
    mStr = new char[1];
    *mStr = '\0';
}

MyString::MyString(const char* str)
{
    if(NULL == str)
    {
        mStr = new char[1];
        *mStr = '\0';
    }
    else
    {
        mStr = new char[strlen(str)+1];
        strcpy(mStr, str);
    }
}

MyString::MyString(const MyString& refStr)
{
    mStr = new char[strlen(refStr.mStr)];
    strcpy(mStr, refStr.mStr);
}

MyString::MyString(int n, char c)
{
    mStr = new char[n+1];
    char* tmp = mStr;
    while(n > 0)
    {
        *tmp = c;
        tmp++;
        n--;
    }

    *tmp = '\0';
}

MyString::~MyString()
{
    if(mStr == NULL)
    {
        delete []mStr;
        mStr = NULL;
    }
}

MyString& MyString::operator=(const char* str)
{
    if (mStr != NULL)
        delete mStr;

    if (str == NULL)
    {
        mStr = new char[1];
        *mStr = '\0';
    }
    else
    {
        mStr = new char[strlen(str)+1];
        strcpy(mStr, str);
    }

    return *this;
}

MyString& MyString::operator=(const MyString& refStr)
{
    if (this == &refStr)
        return *this;

    if (mStr != NULL)
        delete mStr;

    mStr = new char[strlen(refStr.mStr)+1];
    strcpy(mStr, refStr.mStr);

    return *this;
}

char& MyString::operator[](int i)
{
    return mStr[i];
}

const char& MyString::operator[](int i) const
{
    return mStr[i];
}

MyString& MyString::operator+(MyString& refStr)
{
    char* tmp = mStr;
    mStr = new char[strlen(tmp) + strlen(refStr.mStr) + 1];

    strcpy(mStr, tmp);
    delete []tmp;
    strcat(mStr, refStr.mStr);
    return *this;
}

MyString& MyString::operator+=(const MyString& refStr)
{
    char* tmp = mStr;
    mStr = new char[strlen(mStr) + strlen(refStr.mStr) + 1];

    strcpy(mStr, tmp);
    strcat(mStr, refStr.mStr);
    delete []tmp;
    return *this;
}

MyString& MyString::operator+=(const char* str)
{
    if (NULL == str)
        return *this;

    char *tmp = mStr;
    mStr = new char[strlen(str) + strlen(mStr) + 1];

    strcpy(mStr, tmp);
    strcat(mStr, str);
    delete []tmp;
    return *this;
}
