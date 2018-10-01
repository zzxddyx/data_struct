#ifndef _LOOKNBA_H_
#define _LOOKNBA_H_

#include "Observer.h"

class LookNBA : public Observer
{
    public:
        LookNBA(std::string _name, std::string _type)
            :Observer(_name, _type)
            //:name(_name), type(_type)
        {}
        virtual ~LookNBA(){};

    public:
        std::string getName();
        std::string getType();
        void Update(const std::string &);

        /*  
    private:
        std::string name;
        std::string type;
        */
};

#endif //_LOOKNBA_H_
