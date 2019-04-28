/*
    for (declaration : expression)
        statement;
 */
#include <iostream>
#include <cctype>

int main(void)
{
    std::string s("hello");
    
    for (auto &c : s)
        c = std::toupper(c);

    std::cout << s << std::endl;

    return 0;
}
