#ifndef _UNION_H_
#define _UNION_H_

#include <iostream>
#include <string>

class Token
{
    public:
        Token()
            :tok(INT), ival(0)
        {}
        Token(const Token &t)
            :tok(t.tok)
        { copyUnion(t); }
        Token& operator=(const Token &);

        ~Token()
        {
            if (tok == STR) { sval.~string(); }
        }

        Token& operator=(const std::string&);
        Token& operator=(char);
        Token& operator=(int);
        Token& operator=(double);
    private:
        enum { INT, CHAR, DBL, STR }tok; //判别式
        union {
            char        cval;
            int         ival;
            double      dval;
            std::string sval;
        };// 每个Token对象都含有一个未命名的union成员

        void copyUnion(const Token&);
};

#endif //_UNION_H_
