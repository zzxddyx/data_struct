#include <iostream>
#include <memory>

/*
 *  1. allocator与类绑定，因为allocator是一个泛型类
 *  2. allocate()申请指定大小空间
 *  3. construct()构建对象，其参数为可变参数，所以可以选择匹配的构造函数
 *  4. 使用，与其它指针使用无异
 *  5. destroy()析构对象，此时空间还是可以使用
 *  6. deallocate()回收空间
 */
class TestClass
{
    public:
        TestClass(int num = 0)
            :mNum(num)
        {
            std::cout << "TestClass Construct" << std::endl;
        }

        virtual ~TestClass()
        {
            std::cout << "TestClass Destroct" << std::endl;
        }
        void show()
        {
            std::cout << mNum << std::endl;
        }
    private:
        int mNum = 0;
};

int main(void)
{
    std::allocator<TestClass> alloc;    //1
    TestClass *obj1 = alloc.allocate(10); // 2

    // 3
    for (int i = 0; i < 10; ++i)
    {
        alloc.construct(obj1 + i, 10 + i);
    }

    // 4
    for (int i = 0; i < 10; ++i)
    {
        (obj1 + i)->show();
    }

    // 5
    for (int i = 0; i < 10; ++i)
    {
        alloc.destroy(obj1 + i);
    }

    // 6
    alloc.deallocate(obj1, 10);

    return 0;
}

