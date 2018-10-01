#include "Message.h"

Message::Message(const Message &ref)
    :contents(ref.contents), folders(ref.folders)
{
    this->add_to_Folders(ref);
}

Message::~Message()
{
    this->remove_from_Folders();
}

void remove_from_Folders()
{
    for (auto file : this->folders)
    {
        file->remove_from_Folders(this);
    }
}

void Message::save(Folder &file)
{
    folders.insert(&file);
    file.addMsg(this);
}

void Message::remove(Folder &file)
{
    folders.erase(&file);
    file.remMsg(this);
}

void Message::add_to_Folders(const Message &msg)
{
    for (auto file : msg.Folder)
    {
        file->addMsg(this);
    }
}
