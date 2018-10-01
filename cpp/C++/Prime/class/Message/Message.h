#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Message
{
    public:
        friend class Folder;

    public:
        explicit Message(const string &str = "")
            :contents(str)
            {}

        Message(const Message &);
        Message& operator=(Message &);
        ~Message();

    public:
        void save(Folder &);
        void remove(Folder &);

    private:
        string contents; //实际消息文本
        set<Folder*> folders; //包含Message的文件夹

    private:
        void add_to_Folders(const Message &);
        void remove_from_Folders();
};

#endif //_MESSAGE_H_
