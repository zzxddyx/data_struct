/*************************************************************************
    > File Name: MyString.cpp
    > Author: BernieZhao
    > Mail: berniezhao@ezfun.cn
    > Created Time: 2019年05月27日 星期一 22时37分25秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    public:
        MyString(const char* str = NULL)
        {
            cout << "MyString(char*)" << endl;
            if (str == NULL)
            {
                m_String = new char[1];
                *m_String = '\0';
            }
            else
            {
                m_String = new char[strlen(str)+1];
                strcpy(m_String, str);
            }

        }

        MyString(const MyString& ref)
        {
            cout << "MyString(&ref)" <<  endl;
            m_String = new char[strlen(ref.m_String)];
            strcpy(m_String, ref.m_String);
        }

        ~MyString()
        {
            cout << "~MyString()" << endl;
            if (m_String != NULL)
            {
                delete m_String;
                m_String = NULL;
            }
        }

        MyString& operator=(const MyString& ref)
        {
            cout << "MyString(=)" << endl;
            if (this == &ref)
                return *this;

            if (m_String != NULL)
            {
                delete m_String;
                m_String = NULL;
            }

            m_String = new char[strlen(ref.m_String)+1];
            strcpy(m_String, ref.m_String);

            return *this;
        }

        void print()
        {
            cout << m_String << endl;
        }
    private:
        char *m_String;
};

int main(void)
{
    MyString s("Hello");
    s.print();

    MyString s1(s);
    s1.print();

    MyString s2;
    s2 = s1;
    s2.print();

    return 0;
}
