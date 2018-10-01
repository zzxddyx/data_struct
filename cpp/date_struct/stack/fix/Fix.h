#ifndef _FIX_H_
#define _FIX_H_

#include<iostream>
#include <stack>
#include <string>
using namespace std;

class Fix
{
    public:
        int GetResult(string &calc_str);

    private:
        void infixTosuffix(string &infix, string &suffix); // 中缀表达式转为后缀表达式
        int BySuffFixGetResult(string &suffix); // 获取结果
        bool isNumber(char c); // 判断是否操作符
        void HandleOperator(char oper, string &suffix, stack<char> &operator_stack);  // 判断运算符是压入运算符栈还是加到后缀表达式尾
        bool CheckOperatorPriority(char curOperator, char StackTopOperator);
        void loopPushOperInStack(char c, string &suffix, stack<char> &operator_stack); 
        void CalcResult(char value, stack<int> &value_stack);

};

#endif //_FIX_H_

