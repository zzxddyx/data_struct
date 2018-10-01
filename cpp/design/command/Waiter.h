#ifndef _WAITER_H_
#define _WAITER_H_

#include <vector>
#include "Command.h"

class Waiter
{
    public:
        Waiter()
        {
            p_mCommandList = new vector<Command *>();
        }

    public:
        void SetOrder(Command *command)
        {
            p_mCommandList.push_back(command);
            std::cout << "Add Kaorou" << std::endl;
        }

        void Notify()
        {
            vector<Command *>::iterator iter = p_mCommandList.begin();
            for(; iter != p_mCommandList.end(); ++iter)
            {           
                    (*iter)->ExecuteCommand();
            }                                   
        }

    private:
        vector<Command *> p_mCommandList;
};

#endif //_WAITER_H_
