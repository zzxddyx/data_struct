#ifndef _DIR_H_
#define _DIR_H_

#include "IFile.h"
#include <string>
#include <list>
using std::string;
using std::list;

class Dir : public IFile
{
    public:
        Dir(string name);
        virtual ~Dir();

    public:
        virtual void display();
        virtual int add(IFile *);
        virtual int remove(IFile *);
        virtual list<IFile*> *getChild();
    private:
        string m_name;
        list<IFile *> *m_list;
};

#endif //_DIR_H_

