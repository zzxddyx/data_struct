#ifndef _INVOKER_H_
#define _INVOKER_H_

// 命令的发起者
#include <list>
#include "Command.h"

class Invoker
{
    public:
        Invoker();

    public:
        void AddCmd(Command *cmd);
        void DelCmd(Command *cmd);
        void Notify();

    private:
        std::list<Command *> m_cmds; //命令队列
};

#endif //_INVOKER_H_
