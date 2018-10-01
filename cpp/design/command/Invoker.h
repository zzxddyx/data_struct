#ifndef _INVOKER_H_
#define _INVOKER_H_

#include <list>
#include "Command.h"

class Invoker
{
    public:
        Invoker();

    public:
        void AddCmd(Command *);
        void DelCmd(Command *);
        void Notigy();

    private:
        std::list<Command *> m_cmds;
};

#endif //_INVOKER_H_
