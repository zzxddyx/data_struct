#include <iostream>
#include <algorithm>
#include <functional>

typedef struct Info
{
    int age;
    std::string name;
}INFO;

template<typename T, typename COMP = std::less<T>>
int compare(const T& arg1, const T& arg2, COMP comp = COMP())
{
    int result = 0;
    if(comp(arg1, arg2))
        result = 1;
    else if(comp(arg1, arg2))
        result = -1;

    return result;
}

struct compareInfo
{
    bool operator()(const INFO &arg1, const INFO &arg2)
    {
        return arg1.age > arg2.age ? true : false;
    }
};

void print(const INFO &info)
{
    std::cout << info.age << " " << info.name << std::endl;
}

int main(void)
{
    INFO info1;
    info1.age = 10;
    info1.name = "JOCK";

    INFO info2;
    info2.age = 100;
    info2.name = "LiMing";

    std::cout << compare<INFO>(info1, info2, compareInfo()) << std::endl;

    print(info1);
    print(info2);

    return 0;
}
