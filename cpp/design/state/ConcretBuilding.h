#ifndef _CONCRETBUILDINT_H_
#define _CONCRETBUILDINT_H_

#include "Building.h"
#include "BuildingState.h"
#include "FireState.h"
#include "ProductionState.h"
#include "RepairState.h"
#include "State.h"
#include "upGradeState.h"

class ConcretBuilding : public Building
{
    public:
        ConcretBuilding(string name)
            :Building(name)
        {
            m_State[BUILDING] = new BuildingState();
        }

        void upGrade()
        {
            map<StateType, State*>::iterator result = m_State.find(UPGRADE);
            if (result == m_State.end())
            {
                m_State[UPGRADE] = new upGradeState();
            }

            eraseState(BUILDING);
            eraseState(PRODUCTION);
        }

        void product()
        {
            map<StateType, State*>::iterator result = m_State.find(PRODUCTION);
            if (result == m_State.end())
            {
                m_State[PRODUCTION] = new ProductionState();
            }

            eraseState(BUILDING);
            eraseState(UPGRADE);
        }

        void injured()
        {
            map<StateType, State*>::iterator result = m_State.find(INJURED);
            if (result == m_State.end())
            {
                m_State[INJURED] = new FireState();
            }
        }

        void repair()
        {
            map<StateType, State*>::iterator injured = m_State.find(INJURED);
            if (injured == m_State.end())
            {
                return;
            }

            map<StateType, State*>::iterator result = m_State.find(REPAIR);
            if (result == m_State.end())
            {
                m_State[REPAIR] = new RepairState();
            }
        }
};

#endif //_CONCRETBUILDINT_H_
