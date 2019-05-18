#include <iostream>

class Base
{
    public:
        Base(int pub = 0, int pro = 0, int pri = 0)
            :mPub(pub), mPro(pro), mPri(pri)
        {}
    public:
        int mPub = 0;
    protected:
        int mPro = 0;
    private:
        int mPri = 0;
};

class Derived : public Base
{
    public:
        Derived(int pub = 0, int pro = 0, int pri = 0)
            :Base(pub, pro, pri)
        {
        }

        void printPub()
        {
            std::cout << mPub << std::endl;
        }

        void printPro()
        {
            std::cout << mPro << std::endl;
        }
        void printPri()
        {
            //std::cout << mPri << std::endl;
        }
};

int main(void)
{
    Derived *obj = new Derived(10, 20, 30);
    obj->printPub();
    obj->printPro();

    return 0;
}
