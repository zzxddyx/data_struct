#ifndef _I_FILE_H_
#define _I_FILE_H_

#include <list>

class IFile
{
    public:
        virtual void display() = 0;
        virtual int add(IFile *) = 0;
        virtual int remove(IFile *) = 0;
        virtual std::list<IFile *>* getChild() = 0;
};

#endif //_I_FILE_H_
