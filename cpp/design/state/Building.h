#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "State.h"
#include <map>
#include <string>
using std::map;
using std::string;

enum StateType
{
    BUILDING, INJURED, REPAIR, UPGRADE, PRODUCTION
};

class Building
{
    public:
        Building(string name)
            :m_Name(name)
        {

        }
        virtual ~Building()
        {

        }

    public:
        virtual void show()
        {
            std::cout << "表现" << std::endl;
            map<StateType, State*>::iterator iter = m_State.begin();
            for ( ; iter !=  m_State.end(); ++iter)
            {
                iter->second->show();
            }
            std::cout << std::endl;
        }

        virtual void eraseState(StateType type)
        {
            map<StateType, State*>::iterator result = m_State.find(type);
            if (result != m_State.end())
            {
                m_State.erase(result);
            }
        }

    protected:
        string m_Name;
        map<StateType, State*> m_State;
};

#endif //_BUILDING_H_

