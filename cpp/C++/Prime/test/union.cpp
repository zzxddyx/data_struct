#include "union.h"

void Token::copyUnion(const Token &t)
{
    switch(t.tok)
    {
        case Token::INT:
            this->ival = t.ival;
            break;
        case Token::CHAR:
            this->cval = t.cval;
            break;
        case Token::DBL:
            this->dval = t.dval;
            break;
        case Token::STR:
            new (&this->sval) string(t.sval);
            break;
    }
}

Token& Token::operator=(const Token &t)
{
    if (this->tok == STR && t.tok != STR)
    {
        this->sval.~string();
    }
    if (this->tok == STR && t.tok == STR)
    {
        sval = t.sval;
    }
    else
    {
        this->copyUnion(t);
    }

    this->tok = t.tok;
    return *this;
}

Token& Token::operator(const std::string &s)
{
    if (this->tok == STR)
    {
        this->sval = s;
    }
    else
    {
        new (&this->sval) string(s);
    }

    this->tok = STR;
    return *this;
}

Token& Token::operator=(char c)
{
    if (this->tok == STR)
    {
        this->sval.~string();
    }
    this->cval = c;
    this->tok
    return *this;
}

Token& Token::operator=(int i)
{
    if (this->tok == STR)
    {
        this->sval.~string();
    }

    this->ival = i;
    this->tok = INT;
    return *this;
}

Token& Token::operator=(double d)
{
    if (this->tok == STR)
    {
        this->sval.~string();
    }

    this->dval = d;
    this->tok = DBL;
    return *this;
}
