#ifndef _FILE_H_
#define _FILE_H_

#include "IFile.h"
#include <string>
#include <list>

using std::string;
using std::list;

class File : public IFile
{
    public:
        File(string name);
        virtual ~File();

    public:
        virtual void display();
        virtual int add(IFile *);
        virtual int remove(IFile *);
        virtual list<IFile *>* getChild();

    private:
        std::string m_name;
};

#endif //_FILE_H_
