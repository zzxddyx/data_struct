#include "Fix.h"

int Fix::GetResult(string &calc_str)
{
    string suffix = "";
    this->infixTosuffix(calc_str, suffix);
    int result = this->BySuffFixGetResult(suffix);
    return result;
}

// infixTosuffix
void Fix::infixTosuffix(string &infix, string &suffix)
{
    cout << "infixTosuffix start ---->" << infix << suffix << endl;
    stack<char> operator_stack;
    for (int i = 0; i < infix.length(); ++i)
    {
        if (infix[i] == ' ')
        {
            continue;
        }
        if (!this->isNumber(infix[i]))
        {
            suffix += infix[i];
        }
        else
        {
            this->HandleOperator(infix[i], suffix, operator_stack);
        }
    }

    if (suffix.length() > 0)
    {
        while (! operator_stack.empty())
        {
            suffix += operator_stack.top();
            operator_stack.pop();
        }
    }
    cout << "infixTosuffix end ------>" << suffix << endl;
}

bool Fix::isNumber(char c)
{
    string s = "+-*/()";
    for (int i = 0; i < s.length(); ++i)
    {
        if (c == s[i])
        {
            return true;
        }
    }
    return false;
}

// 判断运算符是压入运算符栈还是加到后缀表达式尾
void Fix::HandleOperator(char oper, string &suffix, stack<char> &operator_stack)
{
    cout << "HandleOperator start--->" << oper << endl;
    switch (oper)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            // 如果运算符栈为空，直接将运算符压入栈中
            if (operator_stack.empty())
            {
                operator_stack.push(oper);
            }
            else if (this->CheckOperatorPriority(oper, operator_stack.top())) //如果当前运算符优先级小于等于栈顶运算符优先级，则将栈顶运算符加到后缀表达式尾部
            {
                this->loopPushOperInStack(oper, suffix, operator_stack);
                operator_stack.push(oper);
            }
            else //如果当前运算符优先级大于栈顶运算符优先级，则将运算符压栈
            {
                operator_stack.push(oper);
            }
            break;
        case '(':
            operator_stack.push(oper);
            break;
        case ')':
            while(!operator_stack.empty() && operator_stack.top() != '(')
            {
                cout << "pop ')' before suffix " << suffix << " " << operator_stack.top() << endl; 
                suffix += operator_stack.top();
                operator_stack.pop();
            }
            operator_stack.pop();
            break;
        default:
            cout << "recv oper error" << oper << endl;
            break;
    }
}

bool Fix::CheckOperatorPriority(char curOperator, char StackTopOperator)
{
    if (curOperator == '+' || curOperator == '-')
    {
        if (StackTopOperator == '*' || StackTopOperator == '/' || StackTopOperator == '+' || StackTopOperator == '-')
        {
            return true;
        }
    }

    if (curOperator == '*' || curOperator == '/')
    {
        if (StackTopOperator == '*' || StackTopOperator == '/')
        {
            return true;
        }
    }

    return false;
}

void Fix::loopPushOperInStack(char oper, string &suffix, stack<char> &operator_stack)
{
    if (!operator_stack.empty() && this->CheckOperatorPriority(oper, operator_stack.top()))
    {
        suffix += operator_stack.top();
        operator_stack.pop();
        loopPushOperInStack(oper, suffix, operator_stack);
    }
}

int Fix::BySuffFixGetResult(string &suffix)
{
    cout << "BySuffFixGetResult start " << suffix << endl;
    if (suffix.length() < 0)
    {
        return 0;
    }

    stack<int> value_stack;
    for (int i = 0; i < suffix.length(); ++i)
    {
        cout << "check isNumber : " << suffix[i] << " " << isNumber(suffix[i]) << endl;
        if (!this->isNumber(suffix[i]))
        {
            value_stack.push(suffix[i] - '0');
        }
        else
        {
            this->CalcResult(suffix[i], value_stack);
        }
    }

    return value_stack.top();
}

void Fix::CalcResult(char op, stack<int> &value_stack)
{
    cout << "in function CalcResult recv params : " << op << value_stack.empty() << endl;
    if (value_stack.empty())
    {
        return;
    }

    int value1 = value_stack.top();
    value_stack.pop();
    int value2 = value_stack.top();
    value_stack.pop();

    cout << "CalcResult start op and value is : " << value1 << " " << op << " " << value2 << endl;

    int result = 0;
    switch(op)
    {
        case '+':
            result = value1 + value2;
            break;
        case '-':
            result = value1 - value2;
            break;
        case '*':
            result = value1 * value2;
            break;
        case '/':
            value2 = value2 == 0 ? 1 : value2;
            result = value1 / value2;
            break;
    }
    value_stack.push(result);
}
