#ifndef _INVOKET_H_
#define _INVOKET_H_

#include <list>
#include "Command.h"

class Invoker
{
    public:
        Invoker();

    public:
        void AddCmd(Command *);
        void DelCmd(Command *);
        void Notify();

    private:
        std::list<Command *> m_cmds;
};

#endif //_INVOKET_H_
