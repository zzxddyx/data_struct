#include "Invoker.h"
#include <iostream>

Invoker::Invoker()
{
    std::cout << "I'm Command Own" << std::endl;
}

void Invoker::AddCmd(Command *cmd)
{
    m_cmds.push_back(cmd);
}

void Invoker::DelCmd(Command *cmd)
{
    m_cmds.remove(cmd);
}

void Invoker::Notify()
{
    std::list<Command *>::iterator iter = m_cmds.begin();
    for (; iter != m_cmds.end(); ++iter)
    {
        (*iter)->Execute();
    }
}
