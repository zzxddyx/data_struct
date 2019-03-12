#include "MyString.h"

MyString::MyString(const char *str) 
{
    if (str == nullptr) 
    {
        m_str = new char[1];
        m_str[1] = '\0';
    } 
    else 
    {
        int strLength = strlen(str);
        m_str = new char[strLength+1];
        strcpy(m_str, str);
    }
}

MyString::MyString(const MyString &ref) 
{
    int refLength = strlen(ref.m_str);
    m_str = new char[refLength+1];
    strcpy(m_str, ref.m_str);
}

MyString::~MyString() {
    if (m_str != nullptr)
    {
        delete[] m_str;
        m_str = nullptr;
    }
}

MyString& MyString::operator=(const MyString &ref) 
{
    if (this == &ref)
    {
        return *this;
    }

    delete[] m_str;
    m_str = nullptr;

    int refLength = strlen(ref.m_str);
    m_str = new char[refLength+1];
    strcpy(m_str, ref.m_str);

    return *this;
}

void MyString::Print() {
    cout << m_str << endl;
}
