#include <iostream>
using namespace std;

void print(char* str)
{
    cout << "|--------------------------------" << endl;
    cout << "|" << str << ":" << endl;
}

class absTable
{
    public:
        virtual void putTable() = 0;
};

class BaseTable:public absTable
{
    public:
        virtual void putTable()
        {
            print("姓名");
            print("性别");
            print("学历");
            print("年龄");
        }
};

class Decorator:public absTable
{
    public:
        Decorator(absTable* concrateTb):mpAbsTable(concrateTb){}

        virtual void putTable()
        {
            mpAbsTable->putTable();
        }
    private:
        absTable* mpAbsTable;
};

class EnglishDcrt:public Decorator
{
    public:
        EnglishDcrt(absTable* pTb):Decorator(pTb){}

        virtual void putTable()
        {
            print("英语等级");
            Decorator::putTable();
        }
};

class CurWage:public Decorator
{
    public:
        CurWage(absTable* pTb):Decorator(pTb){}

        virtual void putTable()
        {
            print("当前薪水");
            Decorator::putTable();
        }
};

class Experience:public Decorator
{
    public:
        Experience(absTable* pTb):Decorator(pTb){}

        virtual void putTable()
        {
            print("项目经验");
            Decorator::putTable();
        }
};

int main()
{
    BaseTable pro1;
    cout<<"初始表格："<<endl<<endl;
    pro1.putTable();

    cout<<"新表格1："<<endl<<endl;
    EnglishDcrt eng(&pro1);
    eng.putTable();

    cout<<"新表格2："<<endl<<endl;
    CurWage wg(&eng);
    wg.putTable();

    cout<<"新表格3："<<endl<<endl;
    Experience ex(&wg);
    ex.putTable();

    return 0;
}
