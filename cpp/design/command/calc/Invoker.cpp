#include "Invoker.h"

Invoker::Invoker()
{

}

void Invoker::AddCmd(Command *cmd)
{
    this->m_cmds.push_back(cmd);
}

void Invoker::DelCmd(Command *cmd)
{
    this->m_cmds.remove(cmd);
}

void Invoker::Notify()
{
    std::list<Command *>::iterator iter = m_cmds.begin();

    for (; iter != m_cmds.end(); ++iter)
    {
        (*iter)->Execute();
    }
}

