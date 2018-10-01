#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBracket(char c)
{
    if(c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
    {
        return true;
    }
    return false;
}

bool DealMatch(string &str)
{
    stack<char> bracker_stack;
    for (int i = 0; i < str.length(); ++i)
    {
        if (!isBracket(str[i]))
        {
            continue;
        }

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') // 左括号
        {
            bracker_stack.push(str[i]);
        }
        else // 右括号
        {
            if (bracker_stack.empty())
            {
                cout << "less left bracker :" << str[i] << endl;
                return false;
            }
            if (str[i] == ')' && bracker_stack.top() == '(' ||
                str[i] == ']' && bracker_stack.top() == '[' ||
                str[i] == '}' && bracker_stack.top() == '{')
            {
                bracker_stack.pop();
            }
        }
    }

    if (!bracker_stack.empty())
    {
        cout << "less right bracker : " << bracker_stack.top() << endl;
        return false;
    }
    else
    {
        cout << "match successful" << endl;
        return true;
    }
}

int main(void)
{
    string s = "[()]}";
    bool result = DealMatch(s);
    cout << result << endl;

    return 0;
}

