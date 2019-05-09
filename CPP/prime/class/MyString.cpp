#include <iostream>
#include <cstring>
#include <memory>

class MyString
{
    public:
        MyString(const char *str)
        {
            int len = strlen(str)+1;
            mStr = new char[len];
            strcpy(mStr, str);
        }

        MyString(const MyString& ref)
        {
            mStr = new char[strlen(ref.mStr)+1];
            strcpy(mStr, ref.mStr);
        }

        MyString& operator=(MyString &ref)
        {
            if(&ref == this)
                return *this;

            if (mStr != nullptr)
            {
                delete mStr;
                mStr = nullptr;
            }

            mStr = new char[strlen(ref.mStr)+1];
            strcpy(mStr, ref.mStr);

            return *this;
        }

        ~MyString()
        {
            if(mStr != nullptr)
            {
                delete mStr;
                mStr = nullptr;
            }
        }

    public:
        void print()
        {
            std::cout << mStr << std::endl;
        }

    private:
        char *mStr = nullptr;
};

int main(void)
{
    char str[] = "Hello C++";
    MyString *pStr = new MyString(str);
    pStr->print();

    std::shared_ptr<MyString*> p1 = std::make_shared<MyString*>(new MyString("Hello Jock"));
    (*p1)->print();

    MyString *p2(pStr);
    p2->print();



    /*
    MyString *p1;
    MyString *p2;
    p1 = p2 = pStr;
    p1->print();
    p2->print();
    */

    delete pStr;

    return 0;
}
