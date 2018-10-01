#ifndef _ROOMMATE_H_
#define _ROOMMATE_H_

#include "Observer.h"

class RoomMate : public Observer
{
    public:
        RoomMate(std::string _name, std::string _now, std::string _action)
            :name(_name), action(_action), now(_now)
        {}

        virtual ~RoomMate(){};

    public:
        void Update(const std::string &msg);
        std::string getName();

    private:
        std::string name;
        std::string action;
        std::string now;
};

#endif //_ROOMMATE_H_
